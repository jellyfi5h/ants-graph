/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 03:07:45 by aboukhri          #+#    #+#             */
/*   Updated: 2019/10/27 20:26:53 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	create new element point on the adress of a specific room
*/

t_links		*new_link(void *room)
{
	t_links	*new;

	if (!(new = (t_links*)malloc(sizeof(t_links))))
		return (NULL);
	new->addr = room;
	new->next = NULL;
	return (new);
}

void		free_links(t_links *head)
{
	t_links	*next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

void		links_garbage(t_links *links, t_garbage **garbage)
{
	t_links	*ptr;

	ptr = links;
	while (ptr)
	{
		garbage_mem(ptr, garbage);
		ptr = ptr->next;
	}
}

void		new_group(t_group **groups)
{
	t_group	*new;

	if (!(new = (t_group*)malloc(sizeof(t_group))))
		return ;
	new->flow = 0;
	new->sum_depth = 0;
	new->next = NULL;
	if (!(*groups))
	{
		*groups = new;
		(*groups)->tail = *groups;
	}
	else
	{
		(*groups)->tail->next = new;
		(*groups)->tail = (*groups)->tail->next;
	}
}
