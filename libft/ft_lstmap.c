/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 02:45:52 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/20 02:00:34 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list1;
	t_list	*first1;
	t_list	*end;

	list1 = lst;
	while (list1)
	{
		if (list1 == lst)
		{
			end = f(list1);
			first1 = end;
		}
		else
		{
			end->next = f(list1);
			end = end->next;
		}
		list1 = list1->next;
	}
	return (first1);
}
