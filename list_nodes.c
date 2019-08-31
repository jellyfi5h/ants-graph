#include "lem_in.h"

/* create new element in in nodes (new room) */
t_nodes  *new_node(int index, char *room, int st)
{
    t_nodes *new;

    if (!(new = (t_nodes*)malloc(sizeof(t_nodes))))
        return (NULL);
    new->index = vertice.index;
    new->room = vertice.room;
    new->status = vertice.status;
    new->f = (new->status == 's') ? 1 : 0;//if room == start then is full of ants
    new->next = NULL;
    return (new);
}

//convert list of vertices to a hash table
void	cast_list_hash(t_graph graph, t_nodes *lst)
{
	if (!(graph->nodes = (t_nodes**)ft_memalloc(sizeof(t_nodes*) * (graph->len))))
        exit(1);//exit error
    //add to garbage collector
	while (lst)
	{
		hash_node(*lst, graph);
		lst = lst->next;
	}
}

// insert a new room in the list of vertices 
void	add_room(char *line, int index, int status, t_nodes **head)
{
	static t_nodes	*tail;//static to remember the tail of the list
	char **info;

	info = ft_strsplit(line, ' ');
	if (!(*head))
	{
		*head = new_node(index, info[0], status);
		tail = *head;
	}
	else
	{
		tail->next = new_node(index, info[0], status);
		tail = tail->next;
	}
    ft_dbl_strdel(info);
}