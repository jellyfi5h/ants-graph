/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:58:18 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/18 19:47:24 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		read_ants(char *map)
{
	char	*line;
	int		ants;

	line = NULL;
	while (map_next_line(map, &line) > 0)
	{
		if (ft_str_isnum(line))
		{
			if ((ants = ft_atoi(line)) == 0)
				break ;
			free(line);
			return (ants);
		}
		else if (line[0] != '#' || command_map(line + 2) > 0)
			break ;
		ft_strdel(&line);
	}
	if (line != NULL)
		free(line);
	return (0);
}

/*
**	fill a list of vertices and return the first line of links
*/

char	*read_vertices(t_graph *graph)
{
	char	*line;
	char	st;

	st = 0;
	line = NULL;
	while (map_next_line(graph->map, &line) > 0)
	{
		if (line[0] == '#' && line[1] == '#')
			st = command_map(line + 2);
		else if (is_room(line))
		{
			add_room(graph, line, st);
			st = 0;
			graph->len++;
		}
		else if (ft_chrcount(line, '-') == 1 && line[0] != '#')
			return (line);
		else if (line[0] != '#')
			break ;
		ft_strdel(&line);
	}
	if (line != NULL)
		free(line);
	return (NULL);
}

/*
**	read edges from the map and store links between rooms
*/

void	read_edges(t_graph *graph, char *line)
{
	parse_links(line, graph);
	line = NULL;
	while (map_next_line(graph->map, &line) > 0)
	{
		if (ft_chrcount(line, '-') == 1 && line[0] != '#')
			parse_links(line, graph);
		else if (line[0] != '#')
		{
			free(line);
			exit_program(2, "ERROR", graph->garbage);
		}
		else
			ft_strdel(&line);
	}
}

/*
**	fill vertices and edges and check errors
*/

void	parsing(t_graph *graph)
{
	char	*first_link;

	if (!(graph->ants = read_ants(graph->map)))
		exit_program(2, "ERROR", graph->garbage);
	if (!(first_link = read_vertices(graph)) || !graph->source || !graph->sink)
		exit_program(2, "ERROR", graph->garbage);
	cast_list_hash(graph);
	read_edges(graph, first_link);
}
