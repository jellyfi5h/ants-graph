/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:34:34 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/18 17:24:35 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	check if the line givven is contain room name and it's coordinate
*/

int		is_room(char *line)
{
	int		index;
	char	*cord;

	if (line[0] == '#' || line[0] == 'L' || ft_chrcount(line, ' ') != 2)
		return (0);
	cord = ft_strchr(line, ' ') + 1;
	index = 0;
	while (cord[index] != ' ')
	{
		if (!(ft_isdigit(cord[index])))
			return (0);
		index++;
	}
	cord = ft_strrchr(line, ' ') + 1;
	if (!is_str_number(cord) || ft_strlen(cord) > 11 || index > 11)
		return (0);
	return (1);
}

char	command_map(char *line)
{
	int	r;

	r = 0;
	if (ft_strcmp(line, "start") == 0)
		r = 's';
	else if (ft_strcmp(line, "end") == 0)
		r = 'e';
	else
		r = 0;
	return (r);
}

/*
**	parse line givven to link between to room
*/

void	parse_links(char *line, t_graph *graph)
{
	char	**rooms;

	rooms = ft_strsplit(line, '-');
	free(line);
	if (!(link_rooms(rooms, graph)))
	{
		ft_dbl_strdel(rooms);
		exit_program(2, "ERROR", graph->garbage);
	}
	ft_dbl_strdel(rooms);
}

/*
**save the given map to display later
*/

char	*map_content(void)
{
	char	*map;
	char	*line;
	int		pos;
	int		len;

	if (!(map = (char*)malloc(INIT_LEN)))
		exit_program(2, "ERROR", NULL);
	pos = 0;
	len = INIT_LEN;
	while (get_next_line(0, &line) >= 0)
	{
		if (!ft_strlen(line))
		{
			free(line);
			break ;
		}
		if (pos + ft_strlen(line) > len)
		{
			len *= 1.5;
			map = ft_strdupfree(map, len);
		}
		pos = ft_strline(line, &map, pos);
		ft_strdel(&line);
	}
	return (map);
}

/*
**	get the next line of a string each time we call it
*/

int		map_next_line(char *map, char **line)
{
	static	int	pos;
	int			nl;

	if (!map[pos])
		return (0);
	nl = ft_strchrindex(map + pos, '\n');
	if (nl == -1)
	{
		*line = ft_strdup(map + pos);
		pos += ft_strlen(map + pos);
	}
	else
	{
		*line = ft_strsub(map, pos, nl - 1);
		pos += nl;
	}
	return (1);
}
