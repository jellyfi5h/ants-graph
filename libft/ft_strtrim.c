/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:19:47 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/19 15:16:10 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	iswspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	unsigned	int	e;
	unsigned	int	b;

	b = 0;
	e = 0;
	if (s)
	{
		while (iswspace(s[b]) == 1 || s[b] == '\0')
		{
			if (s[b] == '\0')
				return ("");
			b++;
		}
		e = ft_strlen(s) - 1;
		while (iswspace(s[e]) == 1)
			e--;
		return (ft_strsub(s, b, e - b + 1));
	}
	return (NULL);
}
