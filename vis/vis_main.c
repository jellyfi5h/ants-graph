/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <ataleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:09:48 by ataleb            #+#    #+#             */
/*   Updated: 2019/11/16 20:56:31 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	void	init_room_struc(t_visu_room *struc)
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
	struc->smol_x = 9999;
	struc->smol_y = 9999;
	struc->r_width = 0;
	struc->r_height = 0;
	struc->num = 0;
	struc->color.r = 255;
	struc->color.g = 0;
	struc->color.b = 0;
	struc->color.a = 255;
}

static	void	get_scale_by_coordinates(t_visu_room *struc, t_nodes *rooms,
		char *start_name, char *end_name)
{
	while (rooms)
	{
		if (rooms->name == start_name)
		{
			struc->start_xy.x = rooms->coord.x;
			struc->start_xy.y = rooms->coord.y;
		}
		if (rooms->name == end_name)
		{
			struc->end_xy.x = rooms->coord.x;
			struc->end_xy.y = rooms->coord.y;
		}
		if (rooms->coord.x > struc->big_x)
			struc->big_x = rooms->coord.x;
		if (rooms->coord.y > struc->big_y)
			struc->big_y = rooms->coord.y;
		if (rooms->coord.x < struc->smol_x)
			struc->smol_x = rooms->coord.x;
		if (rooms->coord.y < struc->smol_y)
			struc->smol_y = rooms->coord.y;
		(struc->num)++;
		rooms = rooms->next;
	}
}

static	void	get_text_height_width(t_visu_room *struc)
{
	struc->textpos_s.h = struc->r_height / 3;
	struc->textpos_s.w = struc->r_width;
	struc->textpos_e.h = struc->r_height / 3;
	struc->textpos_e.w = struc->r_width;
}

static	void	fill_height_width_and_coordinates(t_visu_room *struc,
		t_nodes *tmp)
{
	struc->i = (struc->big_x - struc->smol_x >= struc->big_y - struc->smol_y) ?
		(struc->big_x - struc->smol_x) : (struc->big_y - struc->smol_y);
	struc->r_width = WINDOW_WIDTH / (struc->i + 1);
	struc->r_height = WINDOW_HEIGHT / (struc->i + 1);
	struc->i = -1;
	while (++struc->i < struc->num)
	{
		struc->points.w = struc->r_width;
		struc->points.h = struc->r_height;
		struc->points.x = (tmp->coord.x * struc->r_width) - (struc->r_width *
				struc->smol_x);
		struc->points.y = (tmp->coord.y * struc->r_height) -
			(struc->r_height * struc->smol_y);
		new_rect_node(&struc->room_rect, struc, struc->i, tmp->name);
		tmp = tmp->next;
	}
	get_text_height_width(struc);
	struc->textpos_s.x = struc->start_xy.x * struc->r_width -
		(struc->r_width * struc->smol_x);
	struc->textpos_s.y = (struc->start_xy.y * struc->r_height) + struc->r_height
		- (struc->r_width * struc->smol_y);
	struc->textpos_e.x = struc->end_xy.x * struc->r_width - (struc->r_width *
			struc->smol_x);
	struc->textpos_e.y = (struc->end_xy.y * struc->r_height) + struc->r_height -
		struc->r_width * struc->smol_y;
}

static	void	sdl_log_and_quit(char *message, t_visu *visu)
{
	SDL_Log("%s\n%s\n", message, SDL_GetError());
	SDL_Quit();
	free_garbage(visu->garbage);
	exit(1);
}

static	void	load_images(t_visu_room *struc, SDL_Renderer *renderer, t_visu *visu)
{
	if (!(struc->text_s = IMG_Load("vis/media/Start.png")))
		sdl_log_and_quit("Start text surface error", visu);
	if (!(struc->text_e = IMG_Load("vis/media/End.png")))
		sdl_log_and_quit("End text surface error", visu);
	if (!(struc->text_ure_s = SDL_CreateTextureFromSurface(renderer,
					struc->text_s)))
		sdl_log_and_quit("Error in start image texture", visu);
	SDL_FreeSurface(struc->text_s);
	if (!(struc->text_ure_e = SDL_CreateTextureFromSurface(renderer,
					struc->text_e)))
		sdl_log_and_quit("Error in end image texture", visu);
	SDL_FreeSurface(struc->text_e);
	if (!(struc->room_surface = IMG_Load("vis/media/room2 copy.png")))
		sdl_log_and_quit("loading image (room)", visu);
}

t_visu_room		*get_room_textures(t_nodes *rooms, t_visu *visu,
		char *start_name, char *end_name)
{
	t_visu_room		*struc;
	t_nodes			*tmp;

	if (!(struc = (t_visu_room *)malloc(sizeof(t_visu_room))))
	{
		printf("Error Malloc room structure\n");
		exit(0);
	}
	//garbage_mem(struc, garbage);
	init_room_struc(struc);
	tmp = rooms;
	get_scale_by_coordinates(struc, rooms, start_name, end_name);
	fill_height_width_and_coordinates(struc, tmp);
	load_images(struc, visu->renderer, visu);
	struc->i = 0;
	while ((struc->i) < struc->num)
	{
		new_texture_node(&struc->room_texture,
				SDL_CreateTextureFromSurface(visu->renderer, struc->room_surface),
				struc->i);
		(struc->i)++;
	}
	SDL_FreeSurface(struc->room_surface);
	return (struc);
}

t_visu_ants		*get_ants_textures(t_graph *graph, SDL_Renderer *renderer,
		t_visu_room *room)
{
	t_visu_ants	*struc;

	if (!(struc = (t_visu_ants *)malloc(sizeof(t_visu_ants))))
		exit(0);
	struc->ant_surface = NULL;
	struc->ant_texture = NULL;
	struc->ant_rect = NULL;
	struc->i = 0;
	room->points.w = room->r_width / 2;
	room->points.h = room->r_height / 2;
	room->points.x = room->textpos_s.x + room->r_width / 4;
	room->points.y = room->textpos_s.y - room->r_height + room->r_height / 4;
	while (struc->i < graph->ants)
	{
		new_rect_node(&struc->ant_rect, room, struc->i, NULL);
		struc->i++;
	}
	struc->ant_surface = IMG_Load("vis/media/antt copy.png");
	struc->i = -1;
	while (++struc->i < graph->ants)
		new_texture_node(&struc->ant_texture,
				SDL_CreateTextureFromSurface(renderer, struc->ant_surface),
				struc->i);
	SDL_FreeSurface(struc->ant_surface);
	return (struc);
}

static	void	search_for_neighbor_rect_and_draw_line(t_visu_edges *struc,
		t_visu *visu)
{
	while (struc->edges)
	{
		struc->neighbor_rect = visu->room_struc->room_rect;
		struc->neighbor = struc->edges->addr;
		while (struc->neighbor_rect != NULL)
		{
			if (struc->neighbor_rect->name == struc->neighbor->name)
				break ;
			struc->neighbor_rect = struc->neighbor_rect->next;
		}
		SDL_RenderDrawLine(visu->renderer, struc->room_rect->rect.x +
				visu->room_struc->room_rect->rect.w / 2,
				struc->room_rect->rect.y +
				visu->room_struc->room_rect->rect.h / 2,
				struc->neighbor_rect->rect.x +
				visu->room_struc->room_rect->rect.h / 2,
				struc->neighbor_rect->rect.y +
				visu->room_struc->room_rect->rect.h / 2);
		struc->edges = struc->edges->next;
	}
}

void			draw_edges(t_nodes *rooms, t_visu *visu)
{
	t_visu_edges	*struc;

	if (!(struc = (t_visu_edges *)malloc(sizeof(t_visu_edges))))
		exit(0);
	struc->lst = rooms;
	while (struc->lst)
	{
		struc->room_rect = visu->room_struc->room_rect;
		struc->edges = struc->lst->edges;
		while (struc->room_rect != NULL)
		{
			if (struc->room_rect->name == struc->lst->name)
				break ;
			struc->room_rect = struc->room_rect->next;
		}
		search_for_neighbor_rect_and_draw_line(struc, visu);
		struc->lst = struc->lst->next;
	}
}

void			move_ant(t_visu *visu, char *src, char *dst, int ant_index)
{
	t_move_ants	st;

	visu->roomrect_tmp = visu->room_struc->room_rect;
	while (visu->roomrect_tmp != NULL)
	{
		if (ft_strcmp(src, visu->roomrect_tmp->name) == 0)
			st.src_rec = visu->roomrect_tmp->rect;
		if (ft_strcmp(dst, visu->roomrect_tmp->name) == 0)
			st.dst_rec = visu->roomrect_tmp->rect;
		visu->roomrect_tmp = visu->roomrect_tmp->next;
	}
	st.src_cords.x = st.src_rec.x + visu->room_struc->room_rect->rect.w / 4;
	st.src_cords.y = st.src_rec.y + visu->room_struc->room_rect->rect.h / 4;
	st.dst_cords.x = st.dst_rec.x + visu->room_struc->room_rect->rect.w / 4;
	st.dst_cords.y = st.dst_rec.y + visu->room_struc->room_rect->rect.h / 4;
	visu->ant_to_move = visu->ants_struc->ant_rect;
	while (visu->ant_to_move != NULL)
	{
		if (visu->ant_to_move->index == ant_index)
			break ;
		visu->ant_to_move = visu->ant_to_move->next;
	}
	calculate_move(st.src_cords, st.dst_cords, visu);
}

static	void	init_visu_struc(t_visu *visu, t_graph *graph)
{
	visu->rooms = graph->rooms;
	visu->bg_surface = NULL;
	visu->bg_texture = NULL;
	visu->room_struc = NULL;
	visu->ants_struc = NULL;
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
	t_visu	*visu;
	void	**ants_array;

	ants_array = NULL;
	if (!(visu = (t_visu *)malloc(sizeof(t_visu))))
	{
		printf("malloc error in visu structure\n");
		exit(1);
	}
	init_visu_struc(visu, graph);
	if (!(visu->renderer = SDL_CreateRenderer(visu->window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		sdl_log_and_quit("Error creating renderer", visu);
	if (!(visu->bg_surface = IMG_Load("vis/media/Winter.jpg")))
		sdl_log_and_quit("Error loading background surface", visu);
	if (!(visu->bg_texture = SDL_CreateTextureFromSurface(visu->renderer,
					visu->bg_surface)))
		sdl_log_and_quit("Error creating background texture", visu);
	SDL_FreeSurface(visu->bg_surface);
	visu->room_struc = get_room_textures(graph->rooms, visu,
			((t_nodes *)graph->source)->name, ((t_nodes *)graph->sink)->name);
	visu->ants_struc = get_ants_textures(graph, visu->renderer,
			visu->room_struc);
	loop(visu, graph, ants_array);
}
