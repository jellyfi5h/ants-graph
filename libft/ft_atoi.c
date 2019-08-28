/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 09:31:48 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/20 01:47:21 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
			|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

static	int		strtonum(const char *str)
{
	long	res;
	int		neg;
	int		counter;

	neg = 1;
	res = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		neg = -1;
	}
	counter = *str - '0';
	while (counter >= 0 && counter < 10)
	{
		res = res * 10 + counter;
		str++;
		counter = *str - '0';
	}
	return (res * neg);
}

int				ft_atoi(const char *str)
{
	int cont;
	int index;

	index = 0;
	cont = 0;
	while (str[index] != '\0')
	{
		if ((str[index] > '0') && (str[index] <= '9'))
			cont++;
		index++;
	}
	if (cont > 10)
	{
		if (str[0] == '-')
			return (0);
		else
			return (-1);
	}
	return (strtonum(str));
}
