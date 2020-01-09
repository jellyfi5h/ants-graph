/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_bfs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:07:05 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/18 19:47:00 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
**	edit capacity capacity of the previous edge by f
*/

static	void	edit_capacity(t_nodes *curr, t_nodes *prev, int f)
{
	t_edges	*edges;

	edges = curr->edges;
	while (edges)
	{
		if (ft_strcmp(prev->name, ((t_nodes*)edges->addr)->name) == 0)
			edges->capacity += f;
		edges = edges->next;
	}
}

/*
**	correct the capacity of links of the rooms of the path finded by bfs
*/

static	void	correct_capacity(t_graph *graph)
{
	t_nodes	*room;
	t_nodes	*parent;

	room = graph->sink;
	while (room && ft_strcmp(room->name, ((t_nodes*)graph->source)->name) != 0)
	{
		parent = room->parent;
		edit_capacity(room, parent, 1);
		edit_capacity(parent, room, -1);
		room->bl = 1;
		room = parent;
	}
	unvisited(graph);
}

static	int		end_road(t_nodes *room)
{
	t_edges	*edges;
	t_nodes	*neighbor;

	edges = room->edges;
	while (edges)
	{
		neighbor = edges->addr;
		if (neighbor->bl && edges->capacity > 0)
			return (0);
		edges = edges->next;
	}
	return (1);
}

static	int		correct_path(t_graph *graph, t_nodes *room,
				t_edges *edge, t_queue *queue)
{
	t_nodes	*neighbor;
	t_nodes	*parent;

	neighbor = edge->addr;
	parent = room->parent;
	if (ft_strcmp(neighbor->name, ((t_nodes*)graph->sink)->name) == 0
			&& edge->capacity > 0)
	{
		neighbor->parent = room;
		correct_capacity(graph);
		return (1);
	}
	else if ((!neighbor->v && edge->capacity > 0) &&
			(room->bl == neighbor->bl || (!room->bl && neighbor->bl) ||
			(room->bl && parent->bl && !neighbor->bl)))
		enqueue_neighbor(queue, neighbor, room);
	else if (!edge->next && room->bl && !parent->bl && end_road(room))
		room->v = 0;
	return (0);
}

/*
**	bfs to coorect path follow links with capacity bigger then one
**	until reach the end and edit cpacities of the founded path
*/

int				correct_bfs(t_graph *graph)
{
	t_queue	queue;
	t_edges	*edges;
	t_nodes	*room;

	init_queue(&queue, graph->source);
	while (queue.front)
	{
		room = ((t_links*)queue.front)->addr;
		edges = room->edges;
		while (edges)
		{
			if (correct_path(graph, room, edges, &queue))
			{
				free_queue(&queue);
				return (1);
			}
			edges = edges->next;
		}
		pop(&queue);
	}
	unvisited(graph);
	return (0);
}
