/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 23:42:33 by aboukhri          #+#    #+#             */
/*   Updated: 2019/10/03 16:48:57 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		i;
	char	*str;

	if (size > SIZEMAX)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	i = -1;
	while (++i < (int)size)
		str[i] = 0;
	return (str);
}
