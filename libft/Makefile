CFILES = ft_strlcpy.c ft_split2.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memcpy.c ft_isalpha.c ft_isprint.c ft_strlen.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memset.c  ft_strncmp.c ft_toupper.c ft_isalnum.c ft_isdigit.c ft_strchr.c  ft_strrchr.c ft_strnstr.c ft_strlcat.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c  
CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
BONUS = ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c
OBC = $(CFILES:.c=.o)
OBB = $(BONUS:.c=.o)

all: $(NAME) 
$(NAME): $(OBC) $(CFILES)
	@ar rcs $(NAME) $(OBC)
bonus : $(OBB)

%.o: %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBB) : 
	@$(CC) $(CFLAGS) -c $(BONUS)
	@ar rcs $(NAME) $(OBB)
clean:
	@rm -f $(OBC) $(OBB)
fclean: clean
	@rm -f $(NAME)
re: fclean all
