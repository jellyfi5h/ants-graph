
NAME=lem-in
SRC=data_structures/manage_list.c data_structures/paths.c data_structures/queue.c data_structures/routes.c edmond_karp/algo.c edmond_karp/correct_bfs.c edmond_karp/grouping_paths.c edmond_karp/score.c parsing/check_map.c parsing/hash_nodes.c parsing/list_edges.c parsing/list_nodes.c parsing/parse.c get_next_line/get_next_line.c move_ants.c lem_in.c test_funcs.c vis/manage_list.c vis/utils.c vis/vis_main.c vis/get_rooms_informations.c vis/ants_movement.c vis/get_and_exec_current_action.c vis/init_vars.c

LIB=libft/libft.a

FLAGS=-Wall -Wextra -Werror
OBJDIR=objs
OBJ=$(SRC:.c=.o)
OBJPATH=$(addprefix objs/, $(OBJ))

all: $(LIB) $(NAME)
	
$(LIB):
	make -C libft

$(NAME): $(LIB) $(OBJPATH)
	gcc $(FLAGS) $(LIB) -L ~/.brew/lib/ -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_gfx $(OBJPATH) -o $(NAME)
$(OBJPATH): $(OBJDIR)/%.o : %.c | $(OBJDIR)
	gcc $(FLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)
	mkdir $(OBJDIR)/parsing
	mkdir $(OBJDIR)/data_structures
	mkdir $(OBJDIR)/edmond_karp
	mkdir $(OBJDIR)/get_next_line
	mkdir $(OBJDIR)/vis

clean:
	make clean -C libft
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
