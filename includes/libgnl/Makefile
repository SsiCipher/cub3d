NAME = libgnl.a
FLAGS = -Wall -Wextra -Werror

SRCS =	get_next_line.c \
		get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c get_next_line.h
	@cc $(FLAGS) -c $< -o $@
	@ar rcs $(NAME) $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
