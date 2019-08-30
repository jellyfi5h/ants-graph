/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:03:17 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/19 17:15:49 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
		newlist->next = NULL;
	}
	else
	{
		if (!(newlist->content = malloc(content_size)))
			return (NULL);
		ft_memmove(newlist->content, content, content_size);
		newlist->content_size = content_size;
		newlist->next = NULL;
	}
	return (newlist);
}
