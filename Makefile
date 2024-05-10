MFILES = pipex.c file.c childs.c  
NAME = pipex
CC = cc
GFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
GNL = Get_Next_Line/get_next_line.c Get_Next_Line/get_next_line_utils.c
PRINTF = ft_printf/libftprintf.a
DPRINT = ft_printf
LIBFT = libft/libft.a
DLIBFT = libft

all: $(NAME)

$(NAME): $(MFILES) $(PRINTF) $(LIBFT) $(GNL)
		$(CC) $(GFLAGS) $(MFILES) $(PRINTF) $(LIBFT) $(GNL) -o $(NAME)

$(PRINTF):
	make -C $(DPRINT)

$(LIBFT):
	make -C $(DLIBFT)
	make -C $(DLIBFT) bonus

clean:
	make -C $(DPRINT) fclean
	make -C $(DLIBFT) fclean
	rm -rf outfile

fclean: clean
	rm -f $(NAME)

re: fclean all