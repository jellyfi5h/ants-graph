/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:16:08 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/07 13:24:19 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*newstr;
	unsigned	int	index;

	if (!(newstr = (char *)malloc(size + 1)))
		return (NULL);
	index = 0;
	while (index < size)
		newstr[index++] = 0;
	newstr[index] = 0;
	return (newstr);
}
