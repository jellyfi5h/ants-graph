/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:07:37 by aboukhri          #+#    #+#             */
/*   Updated: 2019/10/03 14:28:24 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupfree(char *s, int len)
{
	int		i;
	char	*str;

	if (!(str = (char*)malloc(len)))
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		str[i] = s[i];
	str[i] = '\0';
	free(s);
	return (str);
}
