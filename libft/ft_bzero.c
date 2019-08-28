/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:01:51 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/09 16:52:21 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned	int		index;
	unsigned	char	*str;

	str = (unsigned char *)s;
	index = 0;
	while (index < n)
		str[index++] = 0;
	s = (void *)str;
	return (s);
}
