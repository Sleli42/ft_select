# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/11 23:34:26 by lubaujar          #+#    #+#              #
#    Updated: 2016/07/11 23:34:27 by lubaujar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
DEBUG = -g -gmodules -fexceptions -ftrapv -fcommon
LDFLAGS = -I./includes/ -I./libft/include/

SRC			= main.c \
				loop.c \
				termcaps.c \
				clist.c \
				init.c \
				error.c \
				parse_keys.c \
				select_tools.c

OBJ = $(SRC:.c=.o)

	SRCDIR	= ./srcs/
	OBJDIR	= ./objs/
	INCDIR	= ./includes/
	SRCS	= $(addprefix $(SRCDIR), $(SRC))
	OBJS	= $(addprefix $(OBJDIR), $(OBJ))
	INCS	= $(addprefix $(INCDIR), $(INC))

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	@gcc $(FLAGS) -o $@ $^ -L./libft/ -lft -ltermcap
	@echo "\t\t\033[35mexec \033[0m./$(NAME)"

$(OBJS): $(SRCS)
	@make -C libft/
	@gcc $(FLAGS) -c $(SRCS) $(LDFLAGS)
	@echo "\033[35m[ GCC ] \033[0m   *.c"
	@mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)

clean:
	@echo "\033[35m[ DELETE ]\033[0m *.o"
	@$(RM) $(OBJ)
	@$(RM) ./objs/

fclean: clean
	@make fclean -C libft/
	@echo "\033[35m[ DELETE ]\033[0m ./21sh"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

