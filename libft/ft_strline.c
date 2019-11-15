/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:14:02 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/10 23:23:55 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strline(char *line, char **content, int pos)
{
	int		i;

	if (!line || !(*content))
		return (-1);
	if (pos)
		(*content)[pos++] = '\n';
	i = -1;
	while (line[++i])
		(*content)[pos++] = line[i];
	(*content)[pos] = '\0';
	return (pos);
}
