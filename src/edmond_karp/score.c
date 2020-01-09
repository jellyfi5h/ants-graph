/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 05:00:00 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/18 19:47:06 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
**	round the float giveen
*/

static	int	ft_ceil(float number)
{
	if ((number > (int)number))
		return (number + 1);
	else
		return (number);
}

int			calcul_score(int ants, int depth, int nbr_paths)
{
	float	score;

	score = (ants + depth) / (float)nbr_paths;
	return (ft_ceil(score));
}

/*
**	return true if the new score is smaller than the last one
*/

int			check_score(t_group *group, int depth, int ants)
{
	int	old;
	int	new;

	old = calcul_score(ants, group->sum_depth, group->flow);
	new = calcul_score(ants, group->sum_depth + depth, group->flow + 1);
	return ((old >= new) ? 1 : 0);
}

/*
**	return the best group with the best score
*/

t_group		*best_group(t_group *groups, int ants)
{
	t_group	*lst;
	t_group	*grp;
	int		best;
	int		score;

	best = -1;
	grp = NULL;
	lst = groups;
	while (lst)
	{
		score = calcul_score(ants, lst->sum_depth, lst->flow);
		if (!grp || best > score || (best == score && lst->flow > grp->flow))
		{
			best = score;
			grp = lst;
		}
		lst = lst->next;
	}
	return (grp);
}
