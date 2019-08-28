/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:59:38 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/05 12:10:21 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned	int		index;
	unsigned	char	*s1v;
	unsigned	char	*s2v;

	index = 0;
	s1v = (unsigned char *)s1;
	s2v = (unsigned char *)s2;
	while (index < n)
	{
		if (s1v[index] != s2v[index])
			return (s1v[index] - s2v[index]);
		index++;
	}
	return (0);
}
