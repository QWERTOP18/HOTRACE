# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knishiok <knishiok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 09:55:58 by knishiok          #+#    #+#              #
#    Updated: 2025/06/29 16:51:27 by knishiok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VARIANT ?= v1

ifeq ($(VARIANT),v1)
VPATH = srcs/v1-map.c
SRCS_VARIANT = $(shell find srcs/v1-map -name "*.c")
INCS_VARIANT = $(shell find srcs/v1-map -name "*.h")
else ifeq ($(VARIANT),v2)
VPATH = srcs/v2-avl
SRCS_VARIANT = $(shell find srcs/v2-avl -name "*.c")
INCS_VARIANT = $(shell find srcs/v2-avl -name "*.h")
else ifeq ($(VARIANT),v0)
VPATH = srcs/v0-array
SRCS_VARIANT = $(shell find srcs/v0-array -name "*.c")
INCS_VARIANT = $(shell find srcs/v0-array -name "*.h")
else
$(error Invalid VARIANT specified. Use 'v1' or 'v2'.)
endif

SRCS_COMMON = $(shell find srcs/parse -name "*.c") \
	$(shell find srcs/_utils -name "*.c") \
	srcs/main.c
INCS_COMMON = $(shell find srcs/parse -name "*.h") \
	$(shell find srcs/_utils -name "*.h") \
	srcs/interface.h

SRCS = $(SRCS_COMMON) $(SRCS_VARIANT)
INCS = $(INCS_COMMON) $(INCS_VARIANT)

CACHE = cache
OBJS = $(patsubst %.c,$(CACHE)/%.o,$(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -Isrcs/_utils
NAME = hotrace

.PHONY: all clean fclean re run debug

all: $(CACHE) $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)


$(CACHE):
	mkdir -p $(CACHE)


$(CACHE)/%.o: %.c $(INCS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(CACHE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME)

debug: CFLAGS += -g -DDEBUG
debug: re
