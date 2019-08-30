/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbtobase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:31:34 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/09 18:38:26 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static	int		checkbase(char *base)
{
	int i;
	int j;
	int leng;

	i = 0;
	leng = len(base);
	while (i < leng)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (j < leng)
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (1);
}

void			ft_nbtobase(int nbr, char *base)
{
	long	start;
	int		multip;

	start = 1;
	multip = len(base);
	if (checkbase(base))
	{
		if (nbr == 0)
			ft_putchar(base[0]);
		if (nbr < 0)
		{
			nbr *= -1;
			ft_putchar('-');
		}
		while (start <= nbr)
			start *= multip;
		if (start != nbr)
			start /= multip;
		while (start >= 1)
		{
			ft_putchar(base[nbr / start]);
			nbr = nbr % start;
			start /= multip;
		}
	}
}
