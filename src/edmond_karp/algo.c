/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:00:06 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/18 19:46:56 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
**	use bfs of correcting paths (edmond-karp) and storing new group of paths
**	after each correction of paths (change capacity of edges)
*/

void	edmond_karp(t_graph *graph)
{
	while (correct_bfs(graph))
	{
		unblocked_paths(graph);
		new_group(&graph->grp);
		garbage_mem(graph->grp->tail, &graph->garbage);
		graph->grp->tail->routes = NULL;
		while (bfs_paths(graph))
			unvisited(graph);
	}
	if (!graph->grp)
		exit_program(2, "ERROR", graph->garbage);
}

/*
**	reset the visited rooms to unvisited to start new bfs
*/

void	unvisited(t_graph *graph)
{
	struct s_queue	queue;
	t_nodes			*room;
	t_nodes			*neighbor;
	t_edges			*edges;

	init_queue(&queue, graph->source);
	while (queue.front)
	{
		room = ((t_links*)queue.front)->addr;
		room->v = 0;
		edges = room->edges;
		while (edges)
		{
			neighbor = (t_nodes*)edges->addr;
			if (neighbor->v)
			{
				neighbor->v = 0;
				push(&queue, edges->addr);
			}
			edges = edges->next;
		}
		pop(&queue);
	}
}

/*
**	reset all blocked rooms & edges to start new bfs
*/

void	unblocked_paths(t_graph *graph)
{
	struct s_queue	queue;
	t_nodes			*room;
	t_edges			*edges;
	t_nodes			*neighbor;

	init_queue(&queue, graph->source);
	while (queue.front)
	{
		room = ((t_links*)queue.front)->addr;
		edges = room->edges;
		while (edges)
		{
			neighbor = edges->addr;
			if (edges->bl || neighbor->bl)
			{
				edges->bl = 0;
				neighbor->bl = 0;
				push(&queue, edges->addr);
			}
			edges = edges->next;
		}
		pop(&queue);
	}
}
