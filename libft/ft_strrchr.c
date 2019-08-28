/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:08:50 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/09 17:32:56 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*table;

	table = (char *)s + ft_strlen(s);
	while (*table != c)
	{
		if (table == s)
			return (NULL);
		table--;
	}
	return (table);
}
