SRCS = $(shell find . -name "*.c")
INCS = $(shell find . -name "*.h")

CACHE = cache
OBJS = $(patsubst %.c,$(CACHE)/%.o,$(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = hotrace

.PHONY: all clean fclean re run

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
