
#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_nodes  t_nodes;
typedef struct s_edges  t_edges;
typedef struct s_graph  t_graph;

struct  s_coords
{
    int x;
    int y;
};

struct  s_nodes
{
    int index;
    char *room;
    char r;// s: start room | e: end room else ordinary room
    int f:1;// 0: room is empty | 1: room is full of an ant
    //struct s_coords coord;
    t_nodes *next;
};


struct  s_edges
{
    void    *link;//point on the room which they are both connected
    t_edges *next;
};

struct  s_graph
{
    int ants;
    t_nodes **nodes;
    t_edges **edges;
    int len;//number of rooms;
    //list of garbage
};


#endif