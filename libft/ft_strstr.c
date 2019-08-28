/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:03:53 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/09 17:45:49 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *haystack, char *needle)
{
	int		j;
	char	*t;

	while (*haystack != '\0')
	{
		t = haystack;
		j = 0;
		while (*haystack == needle[j] && needle[j] != '\0')
		{
			haystack++;
			j++;
		}
		if (needle[j] == '\0')
			return (t);
		haystack = t + 1;
	}
	if (haystack[0] == '\0' && needle[0] == '\0')
		return (haystack);
	return (0);
}
