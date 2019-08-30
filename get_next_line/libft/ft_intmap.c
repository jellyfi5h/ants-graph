/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:34:52 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/09 18:35:10 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intmap(int *tab, int length, int (*f)(int))
{
	int i;
	int *tabreturn;

	i = 0;
	tabreturn = (int*)malloc(sizeof(int) * (length + 1));
	while (i < length)
	{
		tabreturn[i] = f(tab[i]);
		i++;
	}
	return (tabreturn);
}
