/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:47:13 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/18 19:46:52 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_paths		*new_route(void)
{
	t_paths	*new;

	if (!(new = (t_paths*)malloc(sizeof(t_paths))))
		return (NULL);
	new->nodes = NULL;
	new->depth = -2;
	new->capacity = 0;
	new->next = NULL;
	return (new);
}

void		insert_route(t_paths **routes, t_paths *new)
{
	if (!(*routes))
	{
		*routes = new;
		(*routes)->tail = *routes;
	}
	else
	{
		(*routes)->tail->next = new;
		(*routes)->tail = (*routes)->tail->next;
	}
}

void		free_route(t_paths *route)
{
	if (route->nodes)
		free_links(route->nodes);
	free(route);
}
