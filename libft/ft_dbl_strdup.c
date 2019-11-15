/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 01:02:09 by mfetoui           #+#    #+#             */
/*   Updated: 2019/08/17 17:21:46 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	doublestrlen(char **argv)
{
	int		i;

	i = -1;
	if (argv == NULL)
		return (1);
	while (argv[++i])
		;
	return (i);
}

char		**dbl_strdup(char **env)
{
	char	**new;
	int		i;

	if (!(new = (char**)malloc(sizeof(*new) * (doublestrlen(env) + 1))))
		return (NULL);
	i = -1;
	while (env[++i])
		new[i] = ft_strdup(env[i]);
	new[i] = NULL;
	return (new);
}
