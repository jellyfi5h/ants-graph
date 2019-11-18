/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <ataleb@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:23:48 by ataleb            #+#    #+#             */
/*   Updated: 2019/11/18 15:25:42 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	init_room_struc(t_visu_room *struc)
{
	struc->room_surface = NULL;
	struc->room_texture = NULL;
	struc->room_rect = NULL;
	struc->text_s = NULL;
	struc->text_e = NULL;
	struc->text_ure_s = NULL;
	struc->text_ure_e = NULL;
	struc->big_x = -1;
	struc->big_y = -1;
	struc->smol_x = 9999999;
	struc->smol_y = 9999999;
	struc->r_width = 0;
	struc->r_height = 0;
	struc->num = 0;
	struc->color.r = 255;
	struc->color.g = 0;
	struc->color.b = 0;
	struc->color.a = 255;
}

void	init_visu_struc(t_visu *visu, t_graph *graph)
{
	visu->rooms = graph->rooms;
	visu->bg_surface = NULL;
	visu->bg_texture = NULL;
	visu->roomtexture_tmp = NULL;
	visu->roomrect_tmp = NULL;
	visu->ant_to_move = NULL;
	visu->window = NULL;
	visu->renderer = NULL;
	visu->is_running = 1;
	visu->start = 0;
	visu->speed = 1;
	visu->pause = 0;
	visu->end = 0;
	visu->garbage = graph->garbage;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		sdl_log_and_quit("Init error", visu);
	if (!(visu->window = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0)))
	{
		SDL_Log("Window error %s\n", SDL_GetError());
		SDL_DestroyWindow(visu->window);
		exit(1);
	}
}
