/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:15:17 by mfetoui           #+#    #+#             */
/*   Updated: 2019/08/17 23:01:54 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_realloc(char *str, size_t size)
{
	char	*ptr;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (str != NULL)
	{
		if (!(ptr = (char *)ft_memalloc(sizeof(char)
		* (ft_strlen(str) + size + 1))))
			return (NULL);
		while (str[i] != '\0')
		{
			ptr[j++] = str[i++];
		}
		ptr[j + 1] = '\0';
		ft_strdel(&str);
	}
	else
	{
		if (!(ptr = (char *)ft_memalloc(sizeof(char ) * size + 1)))
			return (NULL);
		ft_bzero(ptr, size);
	}
	return (ptr);
}
