/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_exec_current_action.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 07:10:37 by ataleb            #+#    #+#             */
/*   Updated: 2019/11/18 19:47:40 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

void			**get_ants_array(t_graph *graph, int *score)
{
	void	**ants;
	t_group	*best;

	best = best_group(graph->grp, graph->ants);
	group_capacity(best, graph->ants);
	if (!(ants = ants_division(best, graph->ants)))
		return (NULL);
	*score = calcul_score(graph->ants, best->sum_depth, best->flow);
	return (ants);
}

void			give_right_to_move(t_curr_action *head, t_visu *visu)
{
	t_curr_action *tmp;

	tmp = head;
	while (tmp != NULL)
	{
		visu->ant_to_move = visu->ants_struc.ant_rect;
		while (visu->ant_to_move != NULL)
		{
			if (visu->ant_to_move->index == tmp->ant_index)
			{
				visu->ant_to_move->f = 1;
				break ;
			}
			visu->ant_to_move = visu->ant_to_move->next;
		}
		tmp = tmp->next;
	}
}

void			execute_action(t_curr_action *head, t_visu *visu)
{
	t_curr_action	*tmp;
	int				i;

	i = 0;
	tmp = head;
	give_right_to_move(tmp, visu);
	if (!visu->end)
	{
		while (i < FRAMES)
		{
			tmp = head;
			while (tmp != NULL && visu->pause == 0)
			{
				move_ant(visu, tmp->src, tmp->dst, tmp->ant_index);
				tmp = tmp->next;
			}
			if (visu->pause == 0)
				i += 1;
			show_on_screen(visu);
		}
	}
	else
		show_on_screen(visu);
}

static	void	add_new_action_node(void **ants, t_get_action *s, t_visu *visu)
{
	(void)visu;
	((t_nodes*)((t_links*)ants[s->j])->addr)->full = 0;
	s->next->full = 1;
	ants[s->j] = ((t_links*)ants[s->j])->next;
	new_action_node(&s->head, s, visu);
}

void			get_current_action_and_move(void **ants, int count,
		t_nodes *sink, t_visu *visu)
{
	t_get_action	s;

	s.head = NULL;
	s.i = -1;
	while (++s.i < visu->score)
	{
		s.j = -1;
		while (++s.j < count)
		{
			if (((t_links*)ants[s.j]) && ((t_links*)ants[s.j])->next)
			{
				s.next = ((t_links*)ants[s.j])->next->addr;
				s.curr = (t_nodes*)((t_links*)ants[s.j])->addr;
				if (!s.next->full || ft_strcmp(s.next->name, sink->name) == 0)
					add_new_action_node(ants, &s, visu);
			}
		}
		execute_action(s.head, visu);
		free_current_action(s.head);
		s.head = NULL;
	}
	visu->end = 1;
}
