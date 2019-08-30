/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 22:57:13 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/08 20:16:10 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	num(long int n)
{
	if (n < 0)
		n *= -1;
	if (n < 10)
		return (1);
	return (1 + num(n / 10));
}

char		*ft_itoa(int n)
{
	char		*arr;
	int			c;
	long	int	nbim;

	nbim = n;
	c = num(n);
	if (n < 0)
	{
		if (!(arr = (char *)malloc(c + 2)))
			return (NULL);
		arr[c++ - num(n)] = '-';
		nbim *= -1;
	}
	else
		arr = (char *)malloc(c + 1);
	arr[c--] = '\0';
	if (nbim == 0)
		arr[0] = '0';
	while (nbim != 0)
	{
		arr[c--] = ((nbim % 10) + '0');
		nbim /= 10;
	}
	return (arr);
}
