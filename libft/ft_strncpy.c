/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:26:46 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/09 17:18:06 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned	int	i;
	char			*arr;

	i = 0;
	arr = dst;
	while (*src && i < n)
	{
		*dst = *src;
		src++;
		dst++;
		i++;
	}
	while (i < n)
	{
		*dst = '\0';
		dst++;
		i++;
	}
	return (arr);
}
