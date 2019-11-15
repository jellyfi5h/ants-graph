/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <ataleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:32:51 by ataleb            #+#    #+#             */
/*   Updated: 2019/11/08 07:51:43 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	new_action_node(t_curr_action **head, char *src, char *dst,
		int ant_index)
{
	t_curr_action *new;
	t_curr_action *tmp;

	if (!(new = (t_curr_action *)malloc(sizeof(t_curr_action))))
	{
		printf("New Node Malloc error \n");
		exit(1);
	}
	new->src = src;
	new->dst = dst;
	new->ant_index = ant_index;
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

void	new_texture_node(t_texture **head, SDL_Texture *new_txtr, int i)
{
	t_texture	*new;
	t_texture	*tmp;

	if (!(new = (t_texture *)malloc(sizeof(t_texture))))
		exit(1);
	if (!(new_txtr))
	{
		SDL_Log("Error in creating room texture %s\n", SDL_GetError());
		SDL_Quit();
		exit(1);
	}
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

void	new_rect_node(t_rect **head, int w, int h, int x, int y, int i,
		char *name)
{
	t_rect	*new;
	t_rect	*tmp;

	if (!(new = (t_rect *)malloc(sizeof(t_rect))))
		exit(1);
	new->f = 1;
	new->rect.h = h;
	new->rect.w = w;
	new->rect.x = x;
	new->rect.y = y;
	new->dl.updated_x = x;
	new->dl.updated_y = y;
	new->index = i;
	new->name = name;
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

void	print_rect_list(t_rect *head)
{
	t_rect	*tmp;

	tmp = head;
	printf("       <Printing rect list>      \n");
	while (tmp != NULL)
	{
		printf("|node %d : \"%s\"  =  h : %d, w : %d, x : %d, y : %d|\n",
				tmp->index, tmp->name, tmp->rect.h, tmp->rect.w,
				tmp->rect.x, tmp->rect.y);
		tmp = tmp->next;
	}
}
