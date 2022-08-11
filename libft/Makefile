# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchen <souchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 11:35:52 by souchen           #+#    #+#              #
#    Updated: 2022/08/11 15:46:23 by souchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m
CC = gcc
RM = rm -rf
SRC = ft_atoi.c ft_strlcpy.c\
		 ft_putchar_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_split.c ft_strdup.c ft_strjoin.c \
		ft_strlen.c ft_strncmp.c \
		ft_strtrim.c ft_substr.c ft_strchr.c\
		ft_putstr_fd.c ft_strcmp.c ft_isalpha.c ft_strrchr.c

OBJ = $(SRC:.c=.o)

HEADER = libft.h
FLAGS = -Wall -Werror -Wextra
NAME = libft.a

all: $(NAME)

$(NAME) : $(OBJ)
	 @ar rc $(NAME) $(OBJ)
	 @ranlib $(NAME)

%.o : %.c $(HEADER)
	@echo "$(RED)COMPILING$(RESET) $<"
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean clean all
