NAME	= libft.a

CC		= gcc

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -c

SRCS	= ft_atoi.c ft_bzero.c ft_countword.c ft_intlen.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
	ft_lstnew.c ft_lstrepel.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
	ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
	ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
	ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c \
	ft_strsplit.c ft_strstr.c ft_strsub.c ft_tolower.c ft_toupper.c \
	ft_swap.c get_next_line.c ft_strlenint.c ft_list.c ft_init_list.c \
	ft_view_list.c ft_cpy_lst.c ft_tab.c ft_strjoinfree.c view_tab.c \
	ft_isspace.c ft_list2.c

OBJS	= $(SRCS:.c=.o)

GREEN	= "\033[32m"

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo $(GREEN)"Libft: "$@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
