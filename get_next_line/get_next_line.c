/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <ataleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 22:32:01 by ataleb            #+#    #+#             */
/*   Updated: 2019/11/18 17:43:28 by ataleb           ###   ########.fr       */
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

void	readloop(const int fd, char **str, char *tmp, int *ret)
{
	char buff[BUFF_SIZE + 1];

	while ((ret[0] = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret[0]] = '\0';
		tmp = *str;
		*str = ft_strjoin(tmp, buff);
		free(tmp);
		if ((ft_strchr(buff, '\n')) != NULL)
			break ;
	}
}

int		get_next_line(const int fd, char **line)
{
	static	char	*remember[256];
	char			*str;
	char			buff[BUFF_SIZE + 1];
	int				ret[2];
	char			*tmp;

	if (fd < 0 || !(line) || (read(fd, buff, 0)) < 0)
		return (-1);
	if (!(remember[fd]))
		remember[fd] = ft_strnew(0);
	str = ft_strnew(0);
	tmp = str;
	str = ft_strjoin(tmp, remember[fd]);
	free(tmp);
	readloop(fd, &str, tmp, &ret[0]);
	*line = copy_c_len(*line, str, '\n', &ret[1]);
	if (ret[0] == 0 && remember[fd][0] == 0 && ret[1] == 0)
	{
		free(str);
		return (0);
	}
	free(remember[fd]);
	remember[fd] = ft_strdup(str + ret[1] + 1);
	free(str);
	return (1);
}
