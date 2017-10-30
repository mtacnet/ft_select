# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/11 14:50:14 by mtacnet           #+#    #+#              #
#    Updated: 2017/10/30 13:07:30 by mtacnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_select

GREEN		= "\033[32m"
RESET		= "\033[0m"

# src / obj files
SRC			= main.c \

OBJ			= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# ft library
FT			= ./libft/
FT_LIB 		= $(addprefix $(FT),libft.a)
FT_INC 		= -I ./libft
FT_LNK 		= -L ./libft -l ft -ltermcap

# directories
SRCDIR		= ./src/
INCDIR		= ./includes/
OBJDIR		= ./obj/

all: obj $(FT_LIB) $(NAME)

obj:
		@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
		$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
		@make -C $(FT)

$(NAME):$(OBJ)
		@$(CC) $(OBJ) $(FT_LNK) -lm -o $(NAME)
		@echo $(GREEN)"Compilation done !" $(RESET)

clean:
		@rm -rf $(OBJDIR)
		@make -C $(FT) clean
		@echo $(GREEN)"clean OK" $(RESET)

fclean: clean
		@rm -rf $(NAME)
		@make -C $(FT) fclean
		@echo $(GREEN)"fclean OK" $(RESET)

re: fclean all

.PHONY: all clean fclean re
