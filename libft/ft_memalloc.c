/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:57:14 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/07 13:46:24 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned	char	*wahiav;
	unsigned	int		i;

	if (size > 10000000)
		return (NULL);
	if (!(wahiav = (void *)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
		wahiav[i++] = 0;
	return ((void *)wahiav);
}
