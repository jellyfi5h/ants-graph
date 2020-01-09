/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:09:48 by ataleb            #+#    #+#             */
/*   Updated: 2019/11/18 20:45:06 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

t_visu_ants		get_ants_textures(t_graph *graph, t_visu *visu,
		t_visu_room *room)
{
	t_visu_ants	struc;

	struc.ant_surface = NULL;
	struc.ant_texture = NULL;
	struc.ant_rect = NULL;
	struc.i = 0;
	room->points.w = room->r_width / 2;
	room->points.h = room->r_height / 2;
	room->points.x = room->textpos_s.x + room->r_width / 4;
	room->points.y = room->textpos_s.y - room->r_height + room->r_height / 4;
	while (struc.i < graph->ants)
	{
		visu->name_index.i = struc.i;
		visu->name_index.name = NULL;
		new_rect_node(&struc.ant_rect, room, visu);
		struc.i++;
	}
	struc.ant_surface = IMG_Load("src/vis/media/antt copy.png");
	struc.i = -1;
	while (++struc.i < graph->ants)
		new_texture_node(&struc.ant_texture,
				SDL_CreateTextureFromSurface(visu->renderer, struc.ant_surface),
				struc.i, visu);
	SDL_FreeSurface(struc.ant_surface);
	return (struc);
}

static	void	search_for_neighbor_rect_and_draw_line(t_visu_edges *struc,
		t_visu *visu)
{
	while (struc->edges)
	{
		struc->neighbor_rect = visu->room_struc.room_rect;
		struc->neighbor = struc->edges->addr;
		while (struc->neighbor_rect != NULL)
		{
			if (struc->neighbor_rect->name == struc->neighbor->name)
				break ;
			struc->neighbor_rect = struc->neighbor_rect->next;
		}
		SDL_RenderDrawLine(visu->renderer, struc->room_rect->rect.x +
				visu->room_struc.room_rect->rect.w / 2,
				struc->room_rect->rect.y +
				visu->room_struc.room_rect->rect.h / 2,
				struc->neighbor_rect->rect.x +
				visu->room_struc.room_rect->rect.h / 2,
				struc->neighbor_rect->rect.y +
				visu->room_struc.room_rect->rect.h / 2);
		struc->edges = struc->edges->next;
	}
}

void			draw_edges(t_nodes *rooms, t_visu *visu)
{
	t_visu_edges	struc;

	struc.lst = rooms;
	while (struc.lst)
	{
		struc.room_rect = visu->room_struc.room_rect;
		struc.edges = struc.lst->edges;
		while (struc.room_rect != NULL)
		{
			if (struc.room_rect->name == struc.lst->name)
				break ;
			struc.room_rect = struc.room_rect->next;
		}
		search_for_neighbor_rect_and_draw_line(&struc, visu);
		struc.lst = struc.lst->next;
	}
}

static	void	loop(t_visu *visu, t_graph *graph, void **ants_array)
{
	while (visu->is_running)
	{
		while (visu->start && visu->is_running)
		{
			ants_array = get_ants_array(graph, &visu->score);
			get_current_action_and_move(ants_array, graph->ants,
					graph->sink, visu);
		}
		while (!visu->start)
		{
			show_on_screen(visu);
			if (SDL_PollEvent(&visu->event))
			{
				if (visu->event.type == SDL_QUIT)
					quit_and_free(visu);
				if (visu->event.type == SDL_KEYDOWN)
				{
					if (visu->event.key.keysym.sym == SDLK_ESCAPE)
						quit_and_free(visu);
					if (visu->event.key.keysym.sym == SDLK_s)
						visu->start = 1;
				}
			}
		}
	}
}

void			vis_main(t_graph *graph)
{
	t_visu	visu;
	void	**ants_array;

	ants_array = NULL;
	init_visu_struc(&visu, graph);
	if (!(visu.renderer = SDL_CreateRenderer(visu.window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		sdl_log_and_quit("Error creating renderer", &visu);
	if (!(visu.bg_surface = IMG_Load("src/vis/media/grad2.png")))
		sdl_log_and_quit("Error loading background surface", &visu);
	if (!(visu.bg_texture = SDL_CreateTextureFromSurface(visu.renderer,
					visu.bg_surface)))
		sdl_log_and_quit("Error creating background texture", &visu);
	SDL_FreeSurface(visu.bg_surface);
	visu.room_struc = get_room_textures(graph->rooms, &visu,
			((t_nodes *)graph->source)->name, ((t_nodes *)graph->sink)->name);
	visu.ants_struc = get_ants_textures(graph, &visu,
			&visu.room_struc);
	loop(&visu, graph, ants_array);
}
