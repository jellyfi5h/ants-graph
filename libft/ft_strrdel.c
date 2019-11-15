/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 03:03:23 by aboukhri          #+#    #+#             */
/*   Updated: 2019/08/17 17:41:39 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrdel(char *s, int c)
{
	int		len;
	char	*str;
	int		i;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == c)
		{
			s[len] = '\0';
			break ;
		}
		len--;
	}
	if (!(str = (char*)ft_memalloc(len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		str[i] = s[i];
	}
	free(s);
	return (str);
}
