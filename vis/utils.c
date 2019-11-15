/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <ataleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 23:01:32 by ataleb            #+#    #+#             */
/*   Updated: 2019/11/13 12:01:01 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void			quit_and_free(t_visu *visu)
{
	SDL_DestroyWindow(visu->window);
	SDL_Quit();
	//free all
	exit(0);
}

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
		visu->ant_to_move = visu->ants_struc->ant_rect;
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
				{
					((t_nodes*)((t_links*)ants[s.j])->addr)->full = 0;
					s.next->full = 1;
					ants[s.j] = ((t_links*)ants[s.j])->next;
					new_action_node(&s.head, s.curr->name, s.next->name, s.j);
				}
			}
		}
		execute_action(s.head, visu);
		free_current_action(s.head);
		s.head = NULL;
	}
	visu->end = 1;
}

static void		manage_events(t_visu *visu)
{
	if (SDL_PollEvent(&visu->event))
	{
		if (visu->event.type == SDL_QUIT)
			quit_and_free(visu);
		if (visu->event.type == SDL_KEYDOWN)
		{
			if (visu->event.key.keysym.sym == SDLK_ESCAPE)
				quit_and_free(visu);
			if (visu->event.key.keysym.sym == SDLK_p)
				visu->pause = 1;
			if (visu->event.key.keysym.sym == SDLK_r)
				visu->pause = 0;
		}
	}
}

static void		render_nodes_and_text_images(t_visu *visu)
{
	while (visu->roomrect_tmp != NULL)
	{
		SDL_RenderCopy(visu->renderer, visu->roomtexture_tmp->texture, NULL,
				&visu->roomrect_tmp->rect);
		visu->roomtexture_tmp = visu->roomtexture_tmp->next;
		visu->roomrect_tmp = visu->roomrect_tmp->next;
	}
	SDL_RenderCopy(visu->renderer, visu->room_struc->text_ure_s, NULL,
			&visu->room_struc->textpos_s);
	SDL_RenderCopy(visu->renderer, visu->room_struc->text_ure_e, NULL,
			&visu->room_struc->textpos_e);
}

void			show_on_screen(t_visu *visu)
{
	manage_events(visu);
	SDL_RenderClear(visu->renderer);
	SDL_RenderCopy(visu->renderer, visu->bg_texture, NULL, NULL);
	draw_edges(visu->rooms, visu);
	visu->roomtexture_tmp = visu->room_struc->room_texture;
	visu->roomrect_tmp = visu->room_struc->room_rect;
	render_nodes_and_text_images(visu);
	visu->roomtexture_tmp = visu->ants_struc->ant_texture;
	visu->roomrect_tmp = visu->ants_struc->ant_rect;
	while (visu->roomrect_tmp != NULL)
	{
		if (visu->start)
		{
			visu->roomrect_tmp->rect.x = (int)visu->roomrect_tmp->dl.updated_x;
			visu->roomrect_tmp->rect.y = (int)visu->roomrect_tmp->dl.updated_y;
		}
		SDL_RenderCopy(visu->renderer, visu->roomtexture_tmp->texture, NULL,
				&visu->roomrect_tmp->rect);
		visu->roomtexture_tmp = visu->roomtexture_tmp->next;
		visu->roomrect_tmp = visu->roomrect_tmp->next;
	}
	SDL_RenderPresent(visu->renderer);
}

void			first_cond(t_visu *visu)
{
	if (visu->ant_to_move->dl.dx >= visu->ant_to_move->dl.dy)
	{
		if (visu->ant_to_move->f)
		{
			visu->ant_to_move->dl.i = 0;
			visu->ant_to_move->f = 0;
		}
		if ((int)visu->ant_to_move->dl.i < visu->ant_to_move->dl.dx)
		{
			visu->ant_to_move->dl.updated_x += visu->xincr;
			visu->ant_to_move->rect.x = (int)visu->ant_to_move->dl.updated_x;
			visu->ant_to_move->dl.updated_y += visu->yincr;
			visu->ant_to_move->rect.y = (int)visu->ant_to_move->dl.updated_y;
			(visu->ant_to_move->dl.i) += fabs(visu->xincr);
		}
	}
}

void			second_cond(t_visu *visu)
{
	if (visu->ant_to_move->dl.dx < visu->ant_to_move->dl.dy)
	{
		if (visu->ant_to_move->f)
		{
			visu->ant_to_move->dl.i = 0;
			visu->ant_to_move->f = 0;
		}
		if ((int)visu->ant_to_move->dl.i < visu->ant_to_move->dl.dy)
		{
			visu->ant_to_move->dl.updated_y += visu->yincr;
			visu->ant_to_move->rect.y = (int)visu->ant_to_move->dl.updated_y;
			visu->ant_to_move->dl.updated_x += visu->xincr;
			visu->ant_to_move->rect.x = (int)visu->ant_to_move->dl.updated_x;
			(visu->ant_to_move->dl.i) += fabs(visu->xincr);
		}
	}
}

void			calculate_move(t_coords src_cords, t_coords dst_cords,
		t_visu *visu)
{
	visu->ant_to_move->dl.dx = abs(dst_cords.x - src_cords.x);
	visu->ant_to_move->dl.dy = abs(dst_cords.y - src_cords.y);
	visu->xincr = (dst_cords.x - src_cords.x) / FRAMES;
	visu->yincr = (dst_cords.y - src_cords.y) / FRAMES;
	first_cond(visu);
	second_cond(visu);
}
