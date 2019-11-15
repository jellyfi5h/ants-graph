/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:20:50 by ataleb            #+#    #+#             */
/*   Updated: 2019/11/13 21:47:01 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H

# define VISU_H

# include "../sdl/include/SDL2/SDL.h"
# include <stdio.h>
# include "../sdl/include/SDL2/SDL_image.h"
# include "../sdl/include/SDL2/SDL_ttf.h"
# include "../sdl/include/SDL2/SDL2_gfxPrimitives.h"
# include "../includes/lem_in.h"
# include <math.h>

# define WINDOW_HEIGHT 1400
# define WINDOW_WIDTH 1400
# define FRAMES 100.0

typedef struct s_texture		t_texture;
typedef struct s_rect			t_rect;
typedef struct s_visu_room		t_visu_room;
typedef struct s_visu_ants		t_visu_ants;
typedef struct s_draw_line		t_draw_line;
typedef	struct s_visu			t_visu;
typedef	struct s_curr_action	t_curr_action;
typedef	struct s_visu_edges		t_visu_edges;
typedef	struct s_move_ants		t_move_ants;
typedef	struct s_get_action		t_get_action;

struct				s_get_action
{
	t_nodes         *next;
	t_nodes         *curr;
	t_curr_action   *head;
	int             i;
	int             j;
};

struct				s_move_ants
{
	SDL_Rect    src_rec;
	SDL_Rect    dst_rec;
	t_coords    src_cords;
	t_coords    dst_cords;
};

struct				s_visu_edges
{
	t_nodes			*lst;
	t_nodes			*neighbor;
	t_edges			*edges;
	t_rect			*room_rect;
	t_rect			*neighbor_rect;
};

struct				s_visu
{
	SDL_Surface		*bg_surface;
	SDL_Texture		*bg_texture;
	t_visu_room		*room_struc;
	t_visu_ants		*ants_struc;
	t_nodes			*rooms;
	t_texture		*roomtexture_tmp;
	t_rect			*roomrect_tmp;
	t_rect			*ant_to_move;
	SDL_Event		event;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	int				is_running;
	int				start;
	int				x;
	int				y;
	double			xincr;
	double			yincr;
	double			speed;
	int				pause;
	int				end;
	int				score;
	t_garbage		*garbage;
};

struct				s_curr_action
{
	char			*src;
	char			*dst;
	int				ant_index;
	t_curr_action	*next;
};

struct				s_draw_line
{
	int				dx;
	int				dy;
	int				error;
	double			updated_x;
	double			updated_y;
	double			i;
};

struct				s_texture
{
	SDL_Texture		*texture;
	int				ant_index;
	t_texture		*next;
};

struct				s_rect
{
	SDL_Rect		rect;
	int				index;
	char			*name;
	t_draw_line		dl;
	int				f:1;
	t_rect			*next;
};

struct				s_visu_ants
{
	SDL_Surface		*ant_surface;
	t_texture		*ant_texture;
	t_rect			*ant_rect;
	int				i;
};

struct				s_visu_room
{
	t_nodes			*tmp;
	SDL_Surface		*room_surface;
	t_texture		*room_texture;
	t_rect			*room_rect;
	SDL_Surface		*text_s;
	SDL_Surface		*text_e;
	SDL_Texture		*text_ure_s;
	SDL_Texture		*text_ure_e;
	SDL_Rect		textpos_s;
	SDL_Rect		textpos_e;
	SDL_Color		color;
	TTF_Font		*font;
	t_coords		start_xy;
	t_coords		end_xy;
	int				num;
	int				i;
	int				big_x;
	int				big_y;
	int				smol_x;
	int				smol_y;
	int				r_width;
	int				r_height;
};

void	vis_main(t_graph *graph);
void	new_texture_node(t_texture **head, SDL_Texture *new_txtr, int i);
void	new_rect_node(t_rect **head, int x, int y, int h, int w, int i,
		char *name);
void	print_rect_list(t_rect *head);
void	calculate_move(t_coords src_cords, t_coords dst_cords, t_visu *h);
void	quit_and_free(t_visu *visu);
void	show_on_screen(t_visu *visu);
void	draw_edges(t_nodes *rooms, t_visu *visu);
void	**get_ants_array(t_graph *graph, int *score);
void	new_action_node(t_curr_action **head, char *src, char *dst,
		int ant_index);
void	free_current_action(t_curr_action *lst);
void	get_current_action_and_move(void **ants, int count,
		t_nodes *sink, t_visu *visu);
void	move_ant(t_visu *visu, char *src, char *dst, int ant_index);

#endif
