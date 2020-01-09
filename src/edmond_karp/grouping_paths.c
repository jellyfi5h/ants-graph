/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouping_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 22:04:37 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/18 19:47:03 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
**	affect to each path of the group giveen number of ants allowed to pass
*/

void		group_capacity(t_group *group, int ants)
{
	t_paths	*routes;
	int		index;
	int		min;

	if (!group || !group->routes)
		return ;
	routes = group->routes;
	min = routes->depth;
	index = 0;
	while (index < ants)
	{
		routes = group->routes;
		while (routes && index < ants)
		{
			if (routes->capacity + routes->depth <= min)
			{
				routes->capacity++;
				index++;
			}
			routes = routes->next;
		}
		min++;
	}
}

/*
**	block the link between the parent and the curr nodes
*/

void		blocked_parent(t_nodes *parent, t_nodes *curr, t_nodes *source)
{
	t_edges	*edges;
	t_nodes	*neighbor;

	if (ft_strcmp(parent->name, source->name) != 0)
		parent->bl = 1;
	edges = parent->edges;
	while (edges)
	{
		neighbor = edges->addr;
		if (ft_strcmp(neighbor->name, curr->name) == 0)
		{
			edges->bl = 1;
			return ;
		}
		edges = edges->next;
	}
}

/*
**	create new path in the last group created
**	if the route creted give us better score
*/

static	int	backtrack_path(t_graph *graph)
{
	t_nodes	*curr;
	t_paths	*route;

	route = new_route();
	curr = graph->sink;
	while (curr)
	{
		if (curr->parent)
			blocked_parent(curr->parent, curr, graph->source);
		push_path(&route->nodes, curr);
		route->depth++;
		curr = curr->parent;
	}
	if (!graph->grp->tail->routes ||
	check_score(graph->grp->tail, route->depth, graph->ants))
	{
		insert_route(&graph->grp->tail->routes, route);
		graph->grp->tail->flow++;
		graph->grp->tail->sum_depth += route->depth;
		garbage_mem(graph->grp->tail->routes->tail, &graph->garbage);
		links_garbage(graph->grp->tail->routes->tail->nodes, &graph->garbage);
		return (1);
	}
	free_route(route);
	return (0);
}

static	int	end_path(t_graph *graph, t_queue *queue,
					t_nodes *room, t_nodes *neighbor)
{
	neighbor->parent = room;
	free_queue(queue);
	return (backtrack_path(graph));
}

/*
**	insert paths in the last created group (tail) and
**	stop when getting bad score
*/

int			bfs_paths(t_graph *graph)
{
	t_queue	queue;
	t_nodes	*room;
	t_edges	*edges;
	t_nodes	*neighbor;

	init_queue(&queue, graph->source);
	while (queue.front)
	{
		room = ((t_links*)queue.front)->addr;
		edges = room->edges;
		while (edges)
		{
			neighbor = edges->addr;
			if (ft_strcmp(neighbor->name, ((t_nodes*)graph->sink)->name) == 0
			&& !edges->capacity && !edges->bl)
				return (end_path(graph, &queue, room, neighbor));
			else if (!neighbor->v && !edges->bl && !neighbor->bl &&
					!edges->capacity)
				enqueue_neighbor(&queue, neighbor, room);
			edges = edges->next;
		}
		pop(&queue);
	}
	return (0);
}
