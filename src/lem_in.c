/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 03:05:40 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/18 20:43:17 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

/*
**	initialize the graph structure
*/

static	void	init_graph(t_graph *graph)
{
	graph->ants = 0;
	graph->grp = NULL;
	graph->hash_nodes = NULL;
	graph->rooms = NULL;
	graph->sink = NULL;
	graph->source = NULL;
	graph->len = 0;
	graph->map = map_content();
	graph->garbage = NULL;
	garbage_mem(graph->map, &graph->garbage);
}

int				is_neighbors(t_nodes *r1, t_nodes *r2)
{
	t_edges *edges;
	t_nodes *neighbor;

	edges = r1->edges;
	while (edges)
	{
		neighbor = edges->addr;
		if (ft_strcmp(neighbor->name, r2->name) == 0)
			return (1);
		edges = edges->next;
	}
	return (0);
}

static	void	src_sink_group(t_graph *graph)
{
	t_paths *route;

	route = NULL;
	new_group(&graph->grp);
	garbage_mem(graph->grp->tail, &graph->garbage);
	route = new_route();
	garbage_mem(route, &graph->garbage);
	push_path(&route->nodes, graph->sink);
	push_path(&route->nodes, graph->source);
	links_garbage(route->nodes, &graph->garbage);
	route->depth += 2;
	insert_route(&graph->grp->tail->routes, route);
	graph->grp->flow++;
	graph->grp->tail->sum_depth += route->depth;
}

int				main(int argc, char **argv)
{
	t_graph	graph;

	init_graph(&graph);
	parsing(&graph);
	if (is_neighbors(graph.source, graph.sink))
		src_sink_group(&graph);
	else
		edmond_karp(&graph);
	ft_putendl(graph.map);
	ft_putchar('\n');
	move_ants(&graph);
	if (argc > 1 && ft_strcmp(argv[1], "-v") == 0)
		vis_main(&graph);
	free_garbage(graph.garbage);
	return (0);
}
