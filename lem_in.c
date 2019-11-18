/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <ataleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 03:05:40 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/18 15:07:05 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include "vis/visu.h"

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


int		is_neighbors(t_nodes *r1, t_nodes *r2)
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

void	to_sink(int ants, t_nodes *sink)
{
	int i;

	i = 0;
	while (++i <= ants)
	{
		ft_putchar('L');
		ft_putnbr(i);
		ft_putchar('-');
		ft_putstr(sink->name);
		if (i < ants)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

int				main(void)
{
	t_graph graph;

	fd = open("/dev/ttys002", O_RDWR);
	init_graph(&graph);
	parsing(&graph);
	if (is_neighbors(graph.source, graph.sink))
	{
		ft_putendl(graph.map);
		ft_putchar('\n');
		to_sink(graph.ants, graph.sink);
	}
	else
	{
		edmond_karp(&graph);
		ft_putendl(graph.map);
		ft_putchar('\n');
		move_ants(&graph);
	}
	//display_groups(graph.grp, graph.ants);
	//ft_putendl(graph.map);
	//ft_putchar('\n');
	//move_ants(&graph);
	vis_main(&graph);
	free_garbage(graph.garbage);
	return (0);
}
