
#include "includes/lem_in.h"

void	display_list(t_nodes *lst)
{
	while (lst)
	{
		dprintf(fd, "room: %s\n",lst->name);
		lst = lst->next;
	}
}

void    display_vertices(t_links **vertices, int len)
{
    t_links *cols;
    t_nodes *room;
    int     i;

    i = -1;
    while (++i < len)
    {
        cols = vertices[i];
        while (cols)
        {
            room = cols->addr;
            dprintf(fd, "room: %s | v: %s | coords: x = %d, y = %d \n", room->name, room->v ? "true" : "false", room->coord.x, room->coord.y);
            cols = cols->next;
        }
    }
}

void    display_edges(t_nodes *rooms)
{
    t_nodes *lst;
    t_nodes *neighbor;
    t_edges *edges;

    lst = rooms;
    while (lst)
    {
        dprintf(fd, "room: %s -> links: ", lst->name);
        edges = lst->edges;	        
        while (edges)
        {
            neighbor = edges->addr;
            dprintf(fd, "\t(%s | %d),\t ", neighbor->name, edges->capacity);
            //if (neighbor->v)
             //   dprintf(fd, "1, \n");
            //dprintf(fd, "0, \n");
            edges = edges->next;
        }
        ft_putchar_fd('\n', fd);
        lst = lst->next;
    }
}

void display_route(t_links *nodes)
{
    t_links *lst;
    t_nodes *room;

    lst = nodes;
    while (lst)
    {
        room = lst->addr;
        dprintf(fd, "%s | ", room->name);
        lst = lst->next;
    }
    ft_putstr_fd(" {} \n", fd);
}

void    display_groups(t_group *groups, int ants)
{
    t_group *lst;
    t_paths *paths;
    int i;
    int j;
    int score;

    i = 1;
    lst = groups;
    while (lst)
    {
        score = calcul_score(ants, lst->sum_depth, lst->flow);
        dprintf(fd, "\n\t------------     Group : %d  | sum_depth: %d | flow: %d |  score: %d   -----------\n", i, lst->sum_depth, lst->flow, score);
        paths = lst->routes;
        j = 1;
        while (paths)
        {
            dprintf(fd, "path %d - depth: %d | capacity: %d -> ", j, paths->depth, paths->capacity);
            display_route(paths->nodes);
            paths = paths->next;
            j++;
        }
        i++;
        lst = lst->next;
    }
}

void    display_group(t_group *group, int ants)
{
    t_paths *paths;
    int j;
    int score;

    score = calcul_score(ants, group->sum_depth, group->flow);
    dprintf(fd, "\n\t------------     Group   | sum_depth: %d | flow: %d |  score: %d   -----------\n", group->sum_depth, group->flow, score);
    paths = group->routes;
    j = 1;
    while (paths)
    {
        dprintf(fd, "path %d - depth: %d | capacity: %d -> ", j, paths->depth, paths->capacity);
        display_route(paths->nodes);
        paths = paths->next;
        j++;
    }
}