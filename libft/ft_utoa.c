/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:06:02 by aboukhri          #+#    #+#             */
/*   Updated: 2019/08/17 17:46:30 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned long int n)
{
	int		i;
	char	*str;

	i = -1;
	if (n == 0)
		return ("0");
	if (!(str = (char*)ft_memalloc(20)))
		return (NULL);
	while (n != 0)
	{
		str[++i] = (n % 10) + '0';
		n /= 10;
	}
	str = ft_strdup(str);
	if (str == NULL)
		return (NULL);
	return (str);
}
