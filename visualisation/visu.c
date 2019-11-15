/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:20:17 by aboukhri          #+#    #+#             */
/*   Updated: 2019/10/24 14:58:43 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualize.h"
#include "../includes/lem_in.h"
# include <term.h>

static t_keyword  g_keyword[] = 
{
    {1, "[ ]"},
    {2, "[S]"},
    {3, "[T]"},
    {4, "[X]"},
    {5, "X"}
};

t_coords    max_screen(t_nodes *nodes)
{
    t_coords max;
    t_nodes *rooms;

    rooms = nodes;
    max = (t_coords){0, 0};
    while (rooms)
    {
        if (max.x < rooms->coord.x)
            max.x = rooms->coord.x;
        if (max.y < rooms->coord.y)
            max.y = rooms->coord.y;
        rooms = rooms->next;
    }
    return (max);
}

char    *keyword_index(int index)
{
    int i;

    i = -1;
    while (++i < 5)
    {
        if (g_keyword[i].index == index)
            return (g_keyword[i].symbol);
    }
    return (NULL);
}
t_coords    min_screen(t_nodes *nodes)
{
    t_coords min;
    t_nodes *rooms;

    rooms = nodes;
    min = (t_coords){rooms->coord.x, rooms->coord.y};
    while (rooms)
    {
        if (min.x > rooms->coord.x)
            min.x = rooms->coord.x;
        if (min.y > rooms->coord.y)
            min.y = rooms->coord.y;
        rooms = rooms->next;
    }
    return (min);
}

void    map_space(t_coords max, t_coords min, t_map *map)
{
    int i;

    map->x_len = (max.x - min.x) + 1;
    map->y_len = (max.y - min.y) + 1;
    map->x_diff = min.x;
    map->y_diff = min.y;
    if (!(map->farm = (int**)ft_memalloc(sizeof(int*) * (map->y_len))))
        return ;
    i = -1;
    while (++i < map->y_len)
    {
        if (!(map->farm[i] = (int*)ft_memalloc(sizeof(int) * (map->x_len))))
            return ;
    }
}



void    fill_rooms(t_nodes *nodes, t_nodes *start, t_nodes *end, t_map *map)
{
    t_nodes *rooms;
    t_coords pos;
    int     symbl_id;

    rooms = nodes;
    while (rooms)
    {
        pos = rooms->coord;
        if (ft_strcmp(start->name, rooms->name) == 0)
            symbl_id = 2;
        else if (ft_strcmp(end->name, rooms->name) == 0)
            symbl_id = 3;
        else
            symbl_id = 1;
        map->farm[pos.y - map->y_diff][pos.x - map->x_diff] = symbl_id;
        rooms = rooms->next;
    }
}

void    display_farm(t_map map)
{
    int i;
    int j;
    char *symbol;

    i = -1;
    tputs(tgetstr("cl", NULL), 0, err_putchar);
    while (++i < map.y_len)
    {
        j = -1;
        while (++j < map.x_len)
        {
            ft_putstr("   ");
            if (map.farm[i][j] != 0 && (symbol = keyword_index(map.farm[i][j])))
            {
                //ft_putstr("   ");
               // tputs(tgoto(tgetstr("ch", NULL), j * 3, 0), 0, err_putchar);
                ft_putstr(symbol);
            }
            
        }
        ft_putstr("\n\n");
    }
}

void    visualization(t_graph graph)
{
    t_map map;
    struct winsize ws;
    t_coords max;
    t_coords min;
    char *term;

    set_termios();
    if (!(term = getenv("TERM")) || !tgetent(NULL, term))
        return ;
      //  ft_putendl("hola2");
    /*tputs(tgetstr("ti", NULL), 0, int_putchar);*/
    ioctl(0, TIOCGWINSZ, &ws);
    max = max_screen(graph.rooms);
    min = min_screen(graph.rooms);
    //ft_putendl("hola3");
    if (max.x * 3 < ws.ws_col && max.y * 2 < ws.ws_row)
    {
     //   ft_putendl("hola4");
        map_space(max, min, &map);
      //  ft_putendl("hola5");
        fill_rooms(graph.rooms, graph.source, graph.sink, &map);
        //ft_putendl("hola6");
        display_farm(map);
        //ft_putendl("hola7");
    }
    //else

   // tputs(tgetstr("te", NULL), 0, int_putchar);*/
    reset_termios();
}

void    set_termios()
{
    struct termios new;

    tcgetattr(1, &new);
    new.c_cflag &= ~(ICANON | ECHO);
    tcsetattr(1, TCSANOW, &new);
}

void    reset_termios()
{
    struct termios old;

    tcgetattr(1, &old);
    old.c_cflag |= ICANON;
    old.c_cflag |= ECHO;
    tcsetattr(1, TCSANOW, &old);
}