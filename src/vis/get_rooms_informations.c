/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms_informations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 06:50:50 by ataleb            #+#    #+#             */
/*   Updated: 2019/11/18 20:44:00 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

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
		t_nodes *tmp, t_visu *visu)
{
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
		visu->name_index.name = tmp->name;
		visu->name_index.i = struc->i;
		new_rect_node(&struc->room_rect, struc, visu);
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

static	void	load_images(t_visu_room *struc, SDL_Renderer *renderer,
		t_visu *visu)
{
	if (!(struc->text_s = IMG_Load("src/vis/media/Start.png")))
		sdl_log_and_quit("Start text surface error", visu);
	if (!(struc->text_e = IMG_Load("src/vis/media/End.png")))
		sdl_log_and_quit("End text surface error", visu);
	if (!(struc->text_ure_s = SDL_CreateTextureFromSurface(renderer,
					struc->text_s)))
		sdl_log_and_quit("Error in start image texture", visu);
	SDL_FreeSurface(struc->text_s);
	if (!(struc->text_ure_e = SDL_CreateTextureFromSurface(renderer,
					struc->text_e)))
		sdl_log_and_quit("Error in end image texture", visu);
	SDL_FreeSurface(struc->text_e);
	if (!(struc->room_surface = IMG_Load("src/vis/media/room2 copy.png")))
		sdl_log_and_quit("loading image (room)", visu);
}

t_visu_room		get_room_textures(t_nodes *rooms, t_visu *visu,
		char *start_name, char *end_name)
{
	t_visu_room		struc;
	t_nodes			*tmp;

	init_room_struc(&struc);
	tmp = rooms;
	get_scale_by_coordinates(&struc, rooms, start_name, end_name);
	struc.i = (struc.big_x - struc.smol_x >= struc.big_y - struc.smol_y) ?
		(struc.big_x - struc.smol_x) : (struc.big_y - struc.smol_y);
	if (struc.i > 100)
	{
		ft_putstr("Map is too big\n");
		quit_and_free(visu);
	}
	fill_height_width_and_coordinates(&struc, tmp, visu);
	load_images(&struc, visu->renderer, visu);
	struc.i = 0;
	while ((struc.i) < struc.num)
	{
		new_texture_node(&struc.room_texture,
				SDL_CreateTextureFromSurface(visu->renderer,
					struc.room_surface), struc.i, visu);
		(struc.i)++;
	}
	SDL_FreeSurface(struc.room_surface);
	return (struc);
}
