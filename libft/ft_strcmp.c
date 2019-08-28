/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataleb <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 07:55:11 by ataleb            #+#    #+#             */
/*   Updated: 2018/10/06 11:43:01 by ataleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (1)
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
		else if (s1[i] == '\0' || s2[i] == '\0')
			return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
		i++;
	}
}
