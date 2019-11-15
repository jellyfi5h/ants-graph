/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:57:25 by aboukhri          #+#    #+#             */
/*   Updated: 2019/10/27 03:15:41 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	push_path(t_links **path, void *addr)
{
	t_links	*new;

	new = new_link(addr);
	new->next = *path;
	*path = new;
}

void	pop_path(t_links **path)
{
	t_links	*next;

	if (!(*path))
		return ;
	next = (*path)->next;
	free((*path));
	*path = next;
}
