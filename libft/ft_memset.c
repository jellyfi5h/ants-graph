/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:58:53 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/09 16:51:18 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned	int		index;
	unsigned	char	*str;

	str = (unsigned char *)b;
	index = 0;
	while (index < n)
		str[index++] = (unsigned char)c;
	b = (void *)str;
	return (b);
}
