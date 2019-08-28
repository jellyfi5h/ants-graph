/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 20:20:08 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/07 20:25:37 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		arr[15];
	int			c;
	long	int	nbim;

	c = 0;
	nbim = n;
	if (nbim == 0)
		write(fd, "0", 1);
	if (nbim < 0)
	{
		write(fd, "-", 1);
		nbim *= (-1);
	}
	while (nbim != 0)
	{
		arr[c] = ((nbim % 10) + '0');
		nbim /= 10;
		c++;
	}
	while ((c - 1) >= 0)
	{
		write(fd, &(arr[c - 1]), 1);
		c--;
	}
}
