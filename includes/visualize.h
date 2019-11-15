/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:26:49 by aboukhri          #+#    #+#             */
/*   Updated: 2019/10/24 14:58:40 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZE_H
#define VISUALIZE_H

# include <termios.h>

# include <curses.h>
# include <sys/ioctl.h>
# include "lem_in.h"

typedef struct s_map t_map;
typedef struct s_keyword t_keyword;

struct      s_keyword
{
    int index;
    char *symbol;
};

struct      s_map
{
    int **farm;
    int x_len;
    int y_len;
    int x_diff;
    int y_diff;
};

/*      termios conf     */
void    set_termios();
void    reset_termios();
void    visualization(t_graph graph);

#endif