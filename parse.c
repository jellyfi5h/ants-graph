#include "lem_in.h"

static  int read_ants()
{
	char *line;
	int ants;

	while (get_next_line(&line))
    {
        if (ft_str_isnum(line))
        {
            if ((ants = ft_atoi(line)) == 0)
            {
                free(line);
                exit(1);//exit error
            }
            free(line);
            return (ants);
        }
        else if (line[0] != '#')
        {
            free(line);
            //exit error
        }
        free(line);
    }
	return (0);
}

//fill a list of vertices and return the first line of links
static char	*read_vertices(t_graph *graph, t_nodes **lst)
{
	char *line;
	int index;
	char st;

	index = -1;
	while (get_next_line(0, &line))
	{
		if (line[0] == '#' && line[1] == '#')//command
			st = command_map(line + 2);
		else if (is_room(line) && ++index)//room
			add_room(line, index, st, lst);
		else if (ft_chrcount(line, '-') == 1)//check if link
		{
			graph->len = index + 1;
			return (line);
		}
		else if (line[0] != '#')//error
		{
			free(line);
			exit(1);//exit_error
		}
		free(line);
	}
	return (NULL);
}

// read edges from the map and store links between rooms
static void    read_edges(t_graph *graph, char *line)
{
	char **rooms;

    graph->nodes = (t_edges**)ft_memalloc(sizeof(t_edges*) * (graph->len));
    //add to garbage collector
	parse_links(line);
	while (get_next_line(&line))
	{
		if (ft_chrcount(line, '-') == 1)//check if it's link
			parse_links(line);
		if (!ft_strlen(line))//empty newline
			break;
		else if (line[0] != '#')
		{
			free(line);
			exit(1);//exit error + free garbage
		}
	}
}

void	*parsing(t_graph *graph)
{
	char	*first_link;
	t_nodes *lst;

	graph->ants = read_ants();// get number of ants or exit in case of an error
	first_link = read_vertices(graph, &lst);//fill a list of vertices and return the first line of links
	cast_list_hash(graph, lst);// convert the list to hash table
	read_edges(graph, first_link);// read from the map and store links between rooms
    if (start_end_link(graph))//check if there is a connection in the links between start and end
        exit(1);//exit error
}