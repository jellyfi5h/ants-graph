/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:58:27 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/09 16:53:22 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned	int		index;
	unsigned	char	*srcv;
	unsigned	char	*destv;

	srcv = (unsigned char *)src;
	destv = (unsigned char *)dst;
	index = 0;
	while (index < n)
	{
		destv[index] = srcv[index];
		index++;
	}
	return (dst);
}
