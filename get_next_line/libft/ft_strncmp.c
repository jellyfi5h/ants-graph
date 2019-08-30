/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 08:02:08 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/09 18:04:27 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] > s2[i])
			return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
		if (s1[i] < s2[i])
			return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
		else if (s1[i] == '\0' || s2[i] == '\0')
			continue;
		i++;
	}
	return (0);
}
