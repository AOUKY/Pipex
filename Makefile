MFILES = pipex.c file.c childs.c
BFILES = pipex_bonus.c file.c childs.c   
NAME = pipex
CC = cc
GFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
GNL = Get_Next_Line/get_next_line.c Get_Next_Line/get_next_line_utils.c
PRINTF = ft_printf/libftprintf.a
DPRINT = ft_printf
LIBFT = libft/libft.a
DLIBFT = libft

all: $(NAME)

$(NAME): $(MFILES) $(PRINTF) $(LIBFT)
	$(CC) $(GFLAGS) $(MFILES) $(PRINTF) $(LIBFT) -o $(NAME)

bonus: $(BFILES) $(PRINTF) $(LIBFT) $(GNL)
	$(CC) $(GFLAGS) $(BFILES) $(PRINTF) $(LIBFT) $(GNL) -o $(NAME)

$(PRINTF):
	make -C $(DPRINT)

$(LIBFT):
	make -C $(DLIBFT)
	make -C $(DLIBFT) bonus

clean:
	make -C $(DPRINT) clean
	make -C $(DLIBFT) clean
	rm -rf outfile

fclean: clean
	make -C $(DPRINT) fclean
	make -C $(DLIBFT) fclean
	rm -f $(NAME)

re: fclean all