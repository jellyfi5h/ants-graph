/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:20:25 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/12 21:39:28 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

/*
**	return string contain one move instruction
*/

static	char	*instr_ant(int ant, char *room)
{
	char	*instr;

	instr = ft_strjoinf("L", ft_itoa(ant), 2);
	instr = ft_strjoinf(instr, "-", 1);
	instr = ft_strjoinf(instr, room, 1);
	instr = ft_strjoinf(instr, " ", 1);
	return (instr);
}

static	char	*one_move(void **ants, int id, t_nodes *sink)
{
	t_nodes	*next;

	next = ((t_links*)ants[id])->next->addr;
	if (!next->full || ft_strcmp(next->name, sink->name) == 0)
	{
		((t_nodes*)((t_links*)ants[id])->addr)->full = 0;
		next->full = 1;
		ants[id] = ((t_links*)ants[id])->next;
		return (instr_ant(id + 1, next->name));
	}
	return (NULL);
}

/*
**	move each ant to the next room with the condition if the room is empty
*/

static	void	sra7_nmal(void **ants, int count, int score, t_nodes *sink)
{
	char	*line;
	int		i;
	int		j;

	i = -1;
	line = NULL;
	while (++i < score)
	{
		j = -1;
		while (++j < count)
		{
			if (((t_links*)ants[j]) && ((t_links*)ants[j])->next)
				line = ft_strjoinf(line, one_move(ants, j, sink), 3);
		}
		if (line)
		{
			ft_putstr_str(line, ft_strlen(line) - 1);
			ft_putchar('\n');
			ft_strdel(&line);
		}
	}
}

/*
**	move ants towards the sink by finding the group with best score
**	and assign to each ant the path to take the rest is srii7
*/

void			move_ants(t_graph *graph)
{
	void	**ants;
	t_group	*best;
	int		score;

	best = best_group(graph->grp, graph->ants);
	group_capacity(best, graph->ants);
	if (!(ants = ants_division(best, graph->ants)))
		return ;
	score = calcul_score(graph->ants, best->sum_depth, best->flow);
	sra7_nmal(ants, graph->ants, score, graph->sink);
	free(ants);
}

/*
**	affect to each ant the first room of a path in the group having best score
*/

void			**ants_division(t_group *best, int len)
{
	void	**ants;
	t_paths	*routes;
	int		i;

	if (!(ants = (void**)ft_memalloc(sizeof(void*) * (len))))
		return (NULL);
	i = -1;
	routes = NULL;
	while (++i < len)
	{
		if (!routes || routes->capacity == 0)
			routes = best->routes;
		ants[i] = routes->nodes;
		routes->capacity--;
		routes = routes->next;
	}
	return (ants);
}
