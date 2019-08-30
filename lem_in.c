
#include "lem_in.h"


int     main()
{
	t_graph graph;

	parse(&graph);//check errors and fill the rooms and edges lists

	return (0);
}

void    parse(t_lemin *graph)
{
	graph->len = check_errors();//errors (1, 3, 4, 7) and get number of rooms
	graph->nodes = (t_nodes**)ft_memalloc(sizeof(t_nodes) * (graph->len + 1));//add to garbage collector
	graph->edges = (t_edges**)ft_memalloc(sizeof(t_edges*) * (graph->len + 1));//add to garbage collector
	fill_vertices(graph);//check errors (5) and fill list of vertices
	fill_edges(graph);//errors (2, 6) and fill list of edges
}


/*
errors:
1- no start or end commands
2- no connected road between start and end
3- start and end has the same room
4- not given number of ants
5- duplicate name of rooms ??? (redefinition may not be considered as an error)
6- not existing room in giving links
7- not respected the order of (ants -> rooms ->links)
 */

//insert all vertices
void    fill_vertices(t_graph *graph)
{
	char *line;
	char **split;
	char r;
	int index;

	r = 0;
	index = 0;
	while (get_next_line(fd, &line) && index < graph->len)
	{
		if (line[0] == '#' && line[1] == '#')
			if ((r = command_map(line + 2)) == 'o') // if command is neither start or end
				exit(1);
		if (is_room(line))
		{
			split = ft_strsplit(line, ' ');
			if (!hash_node((t_node){index, line[0], r, 0, NULL}, graph))//add new node to the hash table 
				exit(1);//exit error + free
			index++;
			//ft_strdbldel(split); free **split
		}
	}
}

int		is_room(char *line)
{
	int	index;
	int	space_count; // every valid room line should contain 2 spaces only (between name and the cords)

	index = 0;
	space_count = 0;
	if (line[0] == '#' || line[0] == 'L') // room will never start with # or L
		return (0);
	while (line[index] != '\0')
	{
		if (line[index] == ' ')
			space_count++;
		index++;
	}
	if (space_count == 2)
		return (1);
	else
		return (0);
}

//check if the command is start or end
char    command_map(char *line)
{
	int r;

	r = 0;
	if (ft_strcmp(line, "start") == 0)
		r = 's';
	else if (ft_strcmp(line, "end") == 0)
		r = 'e';
	else
		r = 'o';
	return (r);
}

//insert all edges
void    fill_edges(t_graph *graph)
{
	char *line;
	char **rooms;


	while (get_next_line(&line))
	{
		if (is_link(line))
		{
			rooms = ft_strsplit(line, '-');
			//add two edges
			//ft_strdbldel(rooms); free **rooms
		}
		else if (line[0] != '#')
			exit(1);//exit error + free garbage
	}
}
