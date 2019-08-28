
#include "lem_in.h"

t_edges    *new_edge(void *room)
{
    t_edges *new;

    if (!(new = (t_edges*)malloc(sizeof(t_edges))))
        return (NULL);
    new->link = room;
    new->next = NULL;
    return (new);
}


void    link_rooms(char **rooms, t_graph *graph)
{
    t_nodes *room_one;
    t_nodes *room_two;
    t_edges *links;

    if (!(room_one = search_room(rooms[0], *graph)))
        return (0);
    if (!(room_two = search_room(rooms[1], *graph)))
        return (0);
    insert_edge(graph, room_two, room_one.index);
    insert_edge(graph, room_one, room_two.index);
}

/* search if there is already an existed link if not insert new link */
void    insert_edge(t_graph *graph, t_nodes *room, int index)
{
    t_edges *lst;

    lst = graph->edges[index];
    while (lst)
    {
        ptr = lst->link;
        if (ptr->index == room->index)
            return ;
        lst = lst->next;
    }
    lst = new_edge(room);
    //add to garbage collector
}

/* search for the room given in the list of vertices and return the element */
t_nodes     *search_room(char *room, t_graph graph)
{
    int hash;
    int pos;
    t_nodes *cls;//collision

    hash = hash_str(rooms[0]);
    pos = hash % graph.len;
    cls = graph.nodes[pos];
    while (cls)
    {
        if (ft_strcmp(cls->room, rooms[0]) == 0)
            return (cls);
        cls = cls->next;
    }
    return (NULL);
}