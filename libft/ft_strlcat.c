/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:56:33 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/09 17:17:36 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		slen(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

size_t			ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int lengthdest;
	unsigned int length;

	i = 0;
	lengthdest = slen(dst);
	j = lengthdest;
	length = lengthdest + slen(src);
	if ((unsigned)j >= size)
		return (length - j + size);
	while (src[i] != '\0' && (unsigned)(i + lengthdest) < size - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (length);
}
