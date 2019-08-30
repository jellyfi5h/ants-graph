/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:23:56 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/09 16:55:32 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned	int		index;
	unsigned	char	*srcv;
	unsigned	char	*destv;
	unsigned	char	mychar;

	mychar = (unsigned char)c;
	srcv = (unsigned char *)src;
	destv = (unsigned char *)dst;
	index = 0;
	while (index < n)
	{
		if (srcv[index] == mychar)
		{
			destv[index] = mychar;
			dst = (void *)destv;
			return (&dst[index + 1]);
		}
		else
		{
			destv[index] = srcv[index];
		}
		index++;
	}
	return (NULL);
}
