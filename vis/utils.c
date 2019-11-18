/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <ataleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 23:01:32 by ataleb            #+#    #+#             */
/*   Updated: 2019/11/17 07:16:31 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void			sdl_log_and_quit(char *message, t_visu *visu)
{
	SDL_Log("%s\n%s\n", message, SDL_GetError());
	SDL_DestroyWindow(visu->window);
	SDL_Quit();
	free_garbage(visu->garbage);
	exit(1);
}

void			quit_and_free(t_visu *visu)
{
	SDL_DestroyWindow(visu->window);
	SDL_Quit();
	free_garbage(visu->garbage);
	exit(0);
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
	SDL_RenderCopy(visu->renderer, visu->room_struc.text_ure_s, NULL,
			&visu->room_struc.textpos_s);
	SDL_RenderCopy(visu->renderer, visu->room_struc.text_ure_e, NULL,
			&visu->room_struc.textpos_e);
}

void			show_on_screen(t_visu *visu)
{
	manage_events(visu);
	SDL_RenderClear(visu->renderer);
	SDL_RenderCopy(visu->renderer, visu->bg_texture, NULL, NULL);
	draw_edges(visu->rooms, visu);
	visu->roomtexture_tmp = visu->room_struc.room_texture;
	visu->roomrect_tmp = visu->room_struc.room_rect;
	render_nodes_and_text_images(visu);
	visu->roomtexture_tmp = visu->ants_struc.ant_texture;
	visu->roomrect_tmp = visu->ants_struc.ant_rect;
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
