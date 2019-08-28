/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:21:26 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/18 21:28:32 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned	int		index;
	char				*fresh;

	if (s != NULL)
	{
		if (!(fresh = (char *)malloc(ft_strlen(s) + 1)))
			return (NULL);
		index = 0;
		while (s[index] != 0)
		{
			fresh[index] = f(index, s[index]);
			index++;
		}
		fresh[index] = 0;
		return (fresh);
	}
	return (NULL);
}
