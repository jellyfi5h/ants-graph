/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:48:50 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/05 12:00:41 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned	int		index;
	unsigned	char	*str;
	void				*sr;

	index = 0;
	str = (unsigned char*)s;
	while (index < n)
	{
		if (str[index] == (unsigned char)c)
		{
			sr = (void *)str;
			return (&(sr[index]));
		}
		index++;
	}
	return (NULL);
}
