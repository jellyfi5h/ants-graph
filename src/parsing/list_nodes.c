/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 10:27:54 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/18 20:49:09 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
**	create new element in in nodes list (new room)
*/

t_nodes		*new_node(char *room, struct s_coords coord)
{
	t_nodes	*new;

	if (!(new = (t_nodes*)malloc(sizeof(t_nodes))))
		return (NULL);
	new->name = ft_strdup(room);
	new->full = 0;
	new->v = 0;
	new->bl = 0;
	new->parent = NULL;
	new->edges = NULL;
	new->coord = coord;
	new->next = NULL;
	return (new);
}

/*
**	convert list of vertices to a hash table & check for status errors
**	(start or end does not exist or start and end in the same node)
*/

void		cast_list_hash(t_graph *graph)
{
	t_nodes	*rooms;

	if (!(graph->hash_nodes = (t_links**)malloc(sizeof(t_links*)
	* (graph->len))))
		exit_program(2, NULL, graph->garbage);
	ft_bzero(graph->hash_nodes, sizeof(t_links*) * (graph->len));
	garbage_mem(graph->hash_nodes, &graph->garbage);
	rooms = graph->rooms;
	while (rooms)
	{
		hash_node(rooms, graph);
		rooms = rooms->next;
	}
}

void		add_room(t_graph *graph, char *line, int status)
{
	static	t_nodes	*tail;
	struct s_coords	coord;
	char			**info;

	info = ft_strsplit(line, ' ');
	coord = (struct s_coords){ft_atoi(info[1]), ft_atoi(info[2])};
	if (!IS_INT(coord.x) || !IS_INT(coord.y))
		exit_program(2, "ERROR", graph->garbage);
	if (!graph->rooms)
	{
		graph->rooms = new_node(info[0], coord);
		tail = graph->rooms;
	}
	else
	{
		tail->next = new_node(info[0], coord);
		tail = tail->next;
	}
	garbage_mem(tail, &graph->garbage);
	garbage_mem(tail->name, &graph->garbage);
	if (status == 's')
		graph->source = tail;
	else if (status == 'e')
		graph->sink = tail;
	ft_dbl_strdel(info);
}
