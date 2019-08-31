
#include "lem_in.h"

int     main()
{
	t_graph graph;

	parsing(&graph);//check errors and fill the rooms and edges lists
	return (0);
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

/* ??? this function will not work in case given just 2 spaces without chars */ 
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
		r = 0;
	return (r);
}

void	parse_links(char *line)//split link to two rooms and exit in case an error
{
	char **rooms;

	rooms = ft_strsplit(line, '-');
	if (!link_rooms(rooms, graph))
	{
		free(line);
		ft_dbl_strdel(rooms);
		exit(1)//exit error
	}
	ft_dbl_strdel(rooms);
	free(line);
}
