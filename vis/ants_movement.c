/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <ataleb@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 07:05:06 by ataleb            #+#    #+#             */
/*   Updated: 2019/11/17 07:07:07 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		first_cond(t_visu *visu)
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

void		second_cond(t_visu *visu)
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

void		calculate_move(t_coords src_cords, t_coords dst_cords,
		t_visu *visu)
{
	visu->ant_to_move->dl.dx = abs(dst_cords.x - src_cords.x);
	visu->ant_to_move->dl.dy = abs(dst_cords.y - src_cords.y);
	visu->xincr = (dst_cords.x - src_cords.x) / FRAMES;
	visu->yincr = (dst_cords.y - src_cords.y) / FRAMES;
	first_cond(visu);
	second_cond(visu);
}

void		move_ant(t_visu *visu, char *src, char *dst, int ant_index)
{
	t_move_ants	st;

	visu->roomrect_tmp = visu->room_struc.room_rect;
	while (visu->roomrect_tmp != NULL)
	{
		if (ft_strcmp(src, visu->roomrect_tmp->name) == 0)
			st.src_rec = visu->roomrect_tmp->rect;
		if (ft_strcmp(dst, visu->roomrect_tmp->name) == 0)
			st.dst_rec = visu->roomrect_tmp->rect;
		visu->roomrect_tmp = visu->roomrect_tmp->next;
	}
	st.src_cords.x = st.src_rec.x + visu->room_struc.room_rect->rect.w / 4;
	st.src_cords.y = st.src_rec.y + visu->room_struc.room_rect->rect.h / 4;
	st.dst_cords.x = st.dst_rec.x + visu->room_struc.room_rect->rect.w / 4;
	st.dst_cords.y = st.dst_rec.y + visu->room_struc.room_rect->rect.h / 4;
	visu->ant_to_move = visu->ants_struc.ant_rect;
	while (visu->ant_to_move != NULL)
	{
		if (visu->ant_to_move->index == ant_index)
			break ;
		visu->ant_to_move = visu->ant_to_move->next;
	}
	calculate_move(st.src_cords, st.dst_cords, visu);
}
