#include "lem_in.h"

/* create new element in in nodes (new room) */
t_nodes  *new_node(t_nodes vertice)
{
    t_nodes *new;

    if (!(new = (t_nodes*)malloc(sizeof(t_nodes))))
        return (NULL);
    new->index = vertice.index;
    new->room = vertice.room;
    new->r = vertice.r;
    new->f = (new->r == 's') ? 1 : 0;//if room == start then is full of ants
    new->next = NULL;
    return (new);
}

int    hash_node(t_nodes new, t_graph *graph)
{
    t_nodes *lst;
    int hash;
    int index;

    hash = hash_str(new.room);
    index = hash % graph->len;
    lst = graph->nodes[index];
    while (lst)//go through the list of collisions values
    {
        if (ft_strcmp(new.room, lst->room) == 0)//check if their any duplicate rooms
            return (0);
        lst = lst->next;
    }
    lst = new_node(new);
    //add to garbage collector
    return (1);
}

int     hash_str(char *str)
{
    int hash;
    int i;

    i = -1;
    hash = 0;
    while (str[++i])
        hash += str[i] * (i + 1);
    return (hash);
}