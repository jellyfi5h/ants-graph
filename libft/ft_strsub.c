/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:39:37 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/19 15:14:12 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	unsigned	int		index;

	if (s)
	{
		index = 0;
		if (!(substr = (char *)malloc(len + 1)))
			return (NULL);
		while (index < (len))
			substr[index++] = s[start++];
		substr[index] = '\0';
		return (substr);
	}
	return (NULL);
}
