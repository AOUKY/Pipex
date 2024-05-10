MFILES = pipex.c file.c childs.c  
NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
GNL = Get_Next_Line/get_next_line.c Get_Next_Line/get_next_line_utils.c
PRINTF = ft_printf/libftprintf.a
DPRINT = ft_printf
LIBFT = libft/libft.a
DLIBFT = libft
HEDER = pipex.h
OBJ = ${MFILES:.c=.o}
OGL = ${GNL:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(LIBFT) $(OGL)
		$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) $(OGL) -o $(NAME)

%.o: %.c $(HEDER)
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	make -C $(DPRINT)

$(LIBFT):
	make -C $(DLIBFT)
	make -C $(DLIBFT) bonus

clean:
	make -C $(DPRINT) fclean
	make -C $(DLIBFT) fclean
	rm -f $(OBJ) $(OGL)

fclean: clean
	rm -f $(NAME)

re: fclean all