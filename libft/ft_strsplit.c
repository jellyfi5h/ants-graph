/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 06:54:49 by aboukhri          #+#    #+#             */
/*   Updated: 2019/08/17 17:45:46 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_words(const char *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\t')
		{
			word++;
			while (s[i] != '\0' && s[i] != c && s[i] != '\t')
				i++;
		}
		else
			i++;
	}
	return (word);
}

static	char	**ft_fill_split(const char *s, char c, char **split)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\t')
		{
			k = 0;
			while (s[i] != '\0' && s[i] != c && s[i] != '\t')
			{
				split[j][k] = s[i];
				i++;
				k++;
			}
			split[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	return (split);
}

static	char	**ft_malloc_tab(const char *s, char c, int len)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	if (!(split = (char **)ft_memalloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\t')
		{
			len = 0;
			while (s[i] != '\0' && s[i] != c && s[i] != '\t')
			{
				i++;
				len++;
			}
			if (!(split[j++] = (char *)malloc(sizeof(char ) * (len + 1))))
				return (NULL);
		}
		else
			i++;
	}
	return (split);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**split;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_words(s, c);
	split = ft_malloc_tab(s, c, len);
	split = ft_fill_split(s, c, split);
	return (split);
}
