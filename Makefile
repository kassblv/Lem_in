NAME   = lem_in
 
CC      =   gcc

CFLAGS  =  -Wall -Wextra -Werror

SRCS    =	ft_init_search_path.c ft_parsing_rooms.c ft_check_rooms.c ft_parsing_bonds.c ft_get_paths.c \
			ft_send_ants.c ft_free.c ft_init_algo.c ft_main.c

LIBFT   =   libft/

OBJS    = $(SRCS:%.c=%.o)

all:        $(NAME);

$(NAME):    $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)libft.a

%.o: %.c
	@$(CC) $(CFLAGS) $< -c -o $@

clean:
	@/bin/rm -rf $(OBJS)
	@make -C $(LIBFT) clean
 
fclean:     clean
	@/bin/rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all
