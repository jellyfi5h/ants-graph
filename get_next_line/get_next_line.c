/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <ataleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 22:32:01 by ataleb            #+#    #+#             */
/*   Updated: 2019/10/13 08:35:53 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*copy_c_len(char *dst, char *src, int c, int *lenc)
{
	*lenc = 0;
	dst = ft_strnew(ft_strlen(src));
	while (src[*lenc] != '\0' && src[*lenc] != (unsigned char)c)
	{
		dst[*lenc] = src[*lenc];
		(*lenc)++;
	}
	return (dst);
}

int		get_next_line(const int fd, char **line)
{
	static	char	*remember[256];
	char			*str;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	int				lenc;

	if (fd < 0 || !(line) || (read(fd, buff, 0)) < 0)
		return (-1);
	if (!(remember[fd]))
		remember[fd] = ft_strnew(0);
	str = ft_strnew(0);
	str = ft_strjoin(str, remember[fd]);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
		if ((ft_strchr(buff, '\n')) != NULL)
			break ;
	}
	*line = copy_c_len(*line, str, '\n', &lenc);
	if (ret == 0 && remember[fd][0] == 0 && lenc == 0)
		return (0);
	remember[fd] = ft_strdup(str + lenc + 1);
	free(str);
	return (1);
}