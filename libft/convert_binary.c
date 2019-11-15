/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 23:39:43 by aboukhri          #+#    #+#             */
/*   Updated: 2019/08/17 17:21:15 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*convert_binary(int dec)
{
	char	*str;
	int		rest;

	if (!(str = (char*)ft_memalloc(1)))
		return (NULL);
	while (dec > 1)
	{
		rest = dec % 2;
		dec /= 2;
		str = ft_strjoin(ft_itoa(rest), str);
		if (dec == 1)
			str = ft_strjoin(ft_itoa(dec), str);
	}
	return (str);
}
