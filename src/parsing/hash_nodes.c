/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:08:06 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/18 19:47:13 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
**	hash string function
*/

int		hash_str(char *str)
{
	int	hash;
	int	i;

	i = -1;
	hash = 0;
	while (str[++i])
		hash += str[i] * (i + 1);
	return (hash);
}

/*
**	fill hash table with pointers on list of nodes
*/

void	hash_node(t_nodes *new, t_graph *graph)
{
	t_links	*lst;
	t_nodes	*room;
	int		index;

	index = hash_str(new->name) % graph->len;
	if (!graph->hash_nodes[index])
	{
		graph->hash_nodes[index] = new_link(new);
		garbage_mem(graph->hash_nodes[index], &graph->garbage);
	}
	else
	{
		lst = graph->hash_nodes[index];
		while (lst)
		{
			room = lst->addr;
			if (ft_strcmp(new->name, room->name) == 0)
				return ;
			if (!lst->next)
				break ;
			lst = lst->next;
		}
		lst->next = new_link(new);
		garbage_mem(lst->next, &graph->garbage);
	}
}
