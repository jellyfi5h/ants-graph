/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:37:30 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/10 23:36:00 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*no_join(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else
		return (ft_strdup(s1));
}

char			*ft_strjoinf(char *s1, char *s2, int rm)
{
	char	*str;

	if (!s1 || !s2)
		str = no_join(s1, s2);
	else
		str = ft_strjoin(s1, s2);
	if (s1 && (rm == 1 || rm == 3))
		ft_strdel(&s1);
	if (s2 && (rm == 2 || rm == 3))
		ft_strdel(&s2);
	return (str);
}
