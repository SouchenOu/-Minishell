# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchen <souchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 11:28:16 by souchen           #+#    #+#              #
#    Updated: 2022/08/11 11:28:24 by souchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m
CC = gcc
FLAGS = -Wall -Werror -Wextra 
#-fsanitize=address
RM = rm -rf

FILES =builtins.c create_env.c  ft_exit.c  ft_unset.c \
       initial_path.c  main.c  run_commande.c \
       divise_commande.c arguments.c arguments_utils.c ft_env.c ft_export.c ft_cd.c ft_pwd.c \
       ft_echo.c output_input.c leaks.c execution.c tools.c split_arg.c creat_env_fun.c  export_tools.c 
 

OBJ_FILES= $(FILES:.c=.o)

HEADER = includes/minishell.h
# HEADER += 
LIBFT = libft/libft.a
NAME = minishell
# LINK=-L/goinfre/readline/a.out.dSYM

all : $(NAME)

$(NAME) : $(OBJ_FILES) $(LIBFT)
	$(CC) $(OBJ_FILES) -lreadline  -L /Users/souchen/goinfre/.brew/opt/readline/lib  -I /Users/souchen/goinfre/.brew/opt/readline/include/readline/ $(LIBFT) $(FLAGS) -o $(NAME)

%.o : %.c $(HEADER)
	@echo $(HOME)
	@echo "$(RED)COMPILING$(RESET) $<"
	$(CC)  $(FLAGS)  -c $< -o $@
$(LIBFT):
	make -C libft

clean:
	$(RM) $(OBJ_FILES)
	@make fclean -C libft

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft
	@echo "\033[0;95m Everything is fcleaned in minishell!\033[m"

re: fclean clean all


    
