# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 09:55:58 by knishiok          #+#    #+#              #
#    Updated: 2025/06/28 15:56:13 by knishiok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 # -fsanitize=address

SRCS = main.c \
	   get_next_line.c \
	   utils.c \
	   AVLtree.c \
	   insert.c \
	   AVL_utils.c \
	   rotate.c 

OBJS = $(SRCS:.c=.o)

INC = -I .

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(OBJS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
