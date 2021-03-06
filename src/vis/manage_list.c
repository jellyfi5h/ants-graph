/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:32:51 by ataleb            #+#    #+#             */
/*   Updated: 2019/11/18 19:47:36 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visu.h"

void	new_action_node(t_curr_action **head, t_get_action *s, t_visu *visu)
{
	t_curr_action *new;
	t_curr_action *tmp;

	if (!(new = (t_curr_action *)malloc(sizeof(t_curr_action))))
		quit_and_free(visu);
	new->src = s->curr->name;
	new->dst = s->next->name;
	new->ant_index = s->j;
	new->next = NULL;
	tmp = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	free_current_action(t_curr_action *lst)
{
	t_curr_action *tmp;

	tmp = NULL;
	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void	new_texture_node(t_texture **head, SDL_Texture *new_txtr, int i,
t_visu *visu)
{
	t_texture	*new;
	t_texture	*tmp;

	if (!(new = (t_texture *)malloc(sizeof(t_texture))))
		exit(1);
	if (!(new_txtr))
	{
		sdl_log_and_quit("Error in creating room texture %s\n", visu);
	}
	garbage_mem(new, &visu->garbage);
	new->texture = new_txtr;
	new->ant_index = i;
	new->next = NULL;
	tmp = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

void	new_rect_node(t_rect **head, t_visu_room *struc, t_visu *visu)
{
	t_rect	*new;
	t_rect	*tmp;

	if (!(new = (t_rect *)malloc(sizeof(t_rect))))
		quit_and_free(visu);
	garbage_mem(new, &visu->garbage);
	new->f = 1;
	new->rect.h = struc->points.h;
	new->rect.w = struc->points.w;
	new->rect.x = struc->points.x;
	new->rect.y = struc->points.y;
	new->dl.updated_x = struc->points.x;
	new->dl.updated_y = struc->points.y;
	new->index = visu->name_index.i;
	new->name = visu->name_index.name;
	new->next = NULL;
	tmp = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
