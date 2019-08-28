/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:26:28 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/09 18:40:07 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	alpha(char c)
{
	if (!((c >= 65 && c <= 90) ||
				(c >= 97 && c <= 122)))
		return (0);
	return (1);
}

static	int	lower(char c)
{
	if (!(c >= 97 && c <= 122))
		return (0);
	return (1);
}

static	int	upper(char c)
{
	if (!(c >= 65 && c <= 90))
		return (0);
	return (1);
}

char		*ft_strcap(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (lower(str[0]) == 1)
			str[0] = str[0] - 32;
		else if ((upper(str[i]) == 1) && ((alpha(str[i - 1]) == 1)
					|| ((str[i - 1] > 47) && (str[i - 1] < 58))))
			str[i] = str[i] + 32;
		else if ((lower(str[i]) == 1) && (alpha(str[i - 1]) == 0) &&
				(!(str[i - 1] >= 48 && str[i - 1] <= 57)))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
