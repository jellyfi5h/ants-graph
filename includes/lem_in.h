/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 10:29:44 by aboukhri          #+#    #+#             */
/*   Updated: 2019/11/18 20:33:50 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

# include <stdio.h>
# include <fcntl.h>

# define IS_INT(x) (x > 2147483647 || x < -2147483648) ? 0 : 1
# define INIT_LEN 1500

typedef	struct s_nodes	t_nodes;
typedef	struct s_edges	t_edges;
typedef	struct s_links	t_links;
typedef	struct s_graph	t_graph;
typedef	struct s_queue	t_queue;
typedef	struct s_paths	t_paths;
typedef	struct s_group	t_group;
typedef	struct s_stack	t_stack;
typedef	struct s_moves	t_moves;
typedef	struct s_coords	t_coords;

struct		s_coords
{
	int	x;
	int	y;
};

struct		s_nodes
{
	char			*name;
	int				full:1;
	int				v:1;
	int				bl:1;
	t_edges			*edges;
	void			*parent;
	struct s_coords	coord;
	t_nodes			*next;
};

struct		s_links
{
	void	*addr;
	t_links	*next;
};

struct		s_edges
{
	void	*addr;
	int		capacity;
	int		bl:1;
	t_edges	*next;
};

struct		s_group
{
	int		flow;
	int		sum_depth;
	t_paths	*routes;
	t_group	*next;
	t_group	*tail;
};

struct		s_graph
{
	int			ants;
	t_nodes		*rooms;
	t_links		**hash_nodes;
	void		*source;
	void		*sink;
	t_group		*grp;
	char		*map;
	int			len;
	int			score;
	t_garbage	*garbage;
};

struct		s_queue
{
	void	*front;
	void	*rear;
	t_links	*fifo;
};

struct		s_paths
{
	t_links	*nodes;
	int		depth;
	int		capacity;
	t_paths	*tail;
	t_paths	*next;
};

/*
**	data structures (add, edit, free)
*/

t_nodes		*new_node(char *room, struct s_coords coord);
t_links		*new_link(void *room);
t_edges		*new_edge(void *room);
void		insert_route(t_paths **head, t_paths *new);
void		new_group(t_group **groups);
void		free_links(t_links *head);
void		links_garbage(t_links *links, t_garbage **garbage);
t_paths		*new_route(void);
void		free_route(t_paths *routes);
void		push(t_queue *queue, void *addr);
int			pop(t_queue *queue);
void		init_queue(struct s_queue *queue, void *data);
void		free_queue(t_queue *queue);

/*
**	parsing map
*/

void		parsing(t_graph *graph);
int			link_rooms(char **rooms, t_graph *graph);
void		*insert_edge(t_nodes *room, t_nodes *neighbor);
t_nodes		*get_room(char *room, t_graph *graph);
void		hash_node(t_nodes *new, t_graph *graph);
int			hash_str(char *str);
char		command_map(char *line);
int			is_room(char *line);
void		parse_links(char *line, t_graph *graph);
void		cast_list_hash(t_graph *graph);
void		add_room(t_graph *graph, char *line, int status);
int			map_next_line(char *map, char **line);
char		*map_content();

/*
**	edmond karp algo
*/

void		edmond_karp(t_graph *graph);
int			correct_bfs(t_graph *graph);
void		unvisited(t_graph *graph);
int			bfs_paths(t_graph *graph);
void		unblocked_paths(t_graph *graph);
void		enqueue_neighbor(t_queue *queue, t_nodes *neighbor,
							t_nodes *parent);

/*
**	move ants
*/

void		move_ants(t_graph *graph);
t_group		*best_group(t_group *groups, int ants);
void		group_capacity(t_group *group, int ants);
int			calcul_score(int ants, int depth, int nbr_paths);
void		**ants_division(t_group *grps, int len);
int			check_score(t_group *group, int depth, int ants);

/*
**	add path in shape of stack
*/

void		push_path(t_links **path, void *addr);
void		pop_path(t_links **path);

/*
**	test_funcs
*/

void		display_list(t_nodes *lst);
void		display_vertices(t_links **vertices, int len);
void		display_edges(t_nodes *rooms);
void		display_groups(t_group *groups, int ants);
void		display_group(t_group *group, int ants);
int			is_neighbors(t_nodes *r1, t_nodes *r2);

#endif
