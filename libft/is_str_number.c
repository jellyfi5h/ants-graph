/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:20:56 by aboukhri          #+#    #+#             */
/*   Updated: 2019/08/08 10:02:22 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_str_number(char *number)
{
	int i;
	int sign;

	i = -1;
	sign = 0;
	while (number[++i])
	{
		if ((number[i] == '-' || number[i] == '+') && !sign && i == 0)
			sign = 1;
		else if (!ft_isdigit(number[i]))
			return (0);
	}
	if (sign && i == 1)
		return (0);
	return (1);
}
