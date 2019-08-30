/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:13:12 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/09 17:43:14 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned	int	ss;

	if (*needle == '\0')
		return ((char *)haystack);
	ss = ft_strlen(needle);
	while (*haystack != '\0' && len-- >= ss)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, ss) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
