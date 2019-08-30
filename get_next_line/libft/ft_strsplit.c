/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:27:29 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/19 15:54:39 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_countwords(char const *s, char c)
{
	int	counter;
	int	index;

	counter = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c && (s[index + 1] == c || s[index + 1] == '\0'))
			counter++;
		index++;
	}
	return (counter);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		counters[3];

	if (!s)
		return (NULL);
	counters[0] = 0;
	counters[1] = 0;
	counters[2] = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1))))
		return (NULL);
	while (counters[0] < ft_countwords(s, c))
		tab[counters[0]++] = (char *)malloc(ft_strlen(s) + 1);
	counters[0] = 0;
	while (s[counters[1]] != '\0')
	{
		while (s[counters[1]] != c && s[counters[1]] != '\0')
			tab[counters[0]][counters[2]++] = s[counters[1]++];
		if (counters[2] != 0)
			tab[counters[0]++][counters[2]] = '\0';
		else
			counters[1]++;
		counters[2] = 0;
	}
	tab[counters[0]] = 0;
	return (tab);
}
