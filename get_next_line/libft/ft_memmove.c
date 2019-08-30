/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:59:30 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/09 02:27:21 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned	int		index;
	unsigned	char	*srcv;
	unsigned	char	*destv;
	unsigned	char	*holder;

	holder = (unsigned char *)malloc(n + 1);
	srcv = (unsigned char *)src;
	destv = (unsigned char *)dest;
	index = 0;
	while (index < n)
	{
		holder[index] = srcv[index];
		index++;
	}
	index = 0;
	while (index < n)
	{
		destv[index] = holder[index];
		index++;
	}
	dest = (void *)destv;
	free(holder);
	return (dest);
}
