/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_putchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:35:11 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/10 23:22:54 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		int_putchar(int c)
{
	write(1, &c, 1);
	return (c);
}
