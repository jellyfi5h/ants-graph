/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 17:41:52 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/09 16:57:19 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	char	*cpy(char *dest, char const *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			*ft_strdup(char const *s1)
{
	char	*des;
	int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	des = (char*)malloc(i + 1);
	if (des == NULL)
		return (NULL);
	cpy(des, s1);
	return (des);
}
