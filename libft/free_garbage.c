/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_garbage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:32:17 by aboukhri          #+#    #+#             */
/*   Updated: 2019/10/04 12:58:36 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_garbage(t_garbage *head)
{
	t_garbage	*next;

	while (head)
	{
		next = head->next;
		if (head->mem_ptr != NULL)
			free(head->mem_ptr);
		free(head);
		head = next;
	}
}
