/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 03:05:57 by aboukhri          #+#    #+#             */
/*   Updated: 2019/08/17 17:22:01 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long int value, int base)
{
	char	*hex;
	char	car[2];
	int		rem;

	if (!(hex = (char*)ft_memalloc(2)))
		return (NULL);
	car[1] = '\0';
	if (value == 0)
		*hex = '0';
	while (value >= 1)
	{
		rem = (value % base);
		value /= base;
		if (rem > 9 && rem < 16 && base == 16)
			car[0] = 'a' + rem - 10;
		else
			car[0] = rem + '0';
		hex = ft_strjoin(car, hex);
	}
	return (hex);
}
