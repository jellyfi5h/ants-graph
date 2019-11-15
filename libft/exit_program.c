/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:24:37 by aboukhri          #+#    #+#             */
/*   Updated: 2019/10/04 12:58:37 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	exit_program(int fd, char *msg, t_garbage *grb)
{
	if (grb != NULL)
		free_garbage(grb);
	ft_putendl_fd(msg, fd);
	(fd == 2 ? exit(1) : exit(0));
}
