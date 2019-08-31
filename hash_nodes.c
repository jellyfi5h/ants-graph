#include "lem_in.h"

static  int     hash_str(char *str)
{
    int hash;
    int i;

    i = -1;
    hash = 0;
    while (str[++i])
        hash += str[i] * (i + 1);
    return (hash);
}

void    hash_node(t_nodes new, t_graph *graph)
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
            return; //not need to add this room is already exist
        lst = lst->next;
    }
    lst = new_node(new);
    //add to garbage collector
}