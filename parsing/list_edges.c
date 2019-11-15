/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 03:30:19 by aboukhri          #+#    #+#             */
/*   Updated: 2019/10/27 03:33:47 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_edges		*new_edge(void *room)
{
	t_edges	*new;

	if (!(new = (t_edges*)malloc(sizeof(t_edges))))
		return (NULL);
	new->addr = room;
	new->capacity = 1;
	new->bl = 0;
	new->next = NULL;
	return (new);
}

int			link_rooms(char **rooms, t_graph *graph)
{
	t_nodes	*room_one;
	t_nodes	*room_two;
	void	*mem;

	if (!(room_one = get_room(rooms[0], graph)))
		return (0);
	if (!(room_two = get_room(rooms[1], graph)))
		return (0);
	if ((mem = insert_edge(room_one, room_two)))
		garbage_mem(mem, &graph->garbage);
	if ((mem = insert_edge(room_two, room_one)))
		garbage_mem(mem, &graph->garbage);
	return (1);
}

/*
**	search if there is already an existed link if not insert new link
*/

void		*insert_edge(t_nodes *room, t_nodes *neighbor)
{
	t_nodes	*node;
	t_edges	*edges;

	if (!room->edges)
	{
		room->edges = new_edge(neighbor);
		return (room->edges);
	}
	edges = room->edges;
	while (edges)
	{
		node = edges->addr;
		if (ft_strcmp(node->name, neighbor->name) == 0)
			return (NULL);
		if (!edges->next)
			break ;
		edges = edges->next;
	}
	edges->next = new_edge(neighbor);
	return (edges->next);
}

/*
**	search for the room given in the list of vertices and return the element
*/

t_nodes		*get_room(char *room, t_graph *graph)
{
	int		index;
	t_links	*cls;
	t_nodes	*node;

	index = hash_str(room) % graph->len;
	cls = graph->hash_nodes[index];
	while (cls)
	{
		node = cls->addr;
		if (ft_strcmp(node->name, room) == 0)
			return (node);
		cls = cls->next;
	}
	return (NULL);
}
