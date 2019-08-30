/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:10:51 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/18 21:28:14 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		index;
	char	*fresh;

	if (s != NULL)
	{
		if (!(fresh = (char *)malloc(ft_strlen(s) + 1)))
			return (NULL);
		index = 0;
		while (s[index] != 0)
		{
			fresh[index] = f(s[index]);
			index++;
		}
		fresh[index] = 0;
		return (fresh);
	}
	return (NULL);
}
