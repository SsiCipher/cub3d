NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c \
		numlen.c \
		put_char.c \
		put_hex.c \
		put_nbr.c \
		put_ptr.c \
		put_str.c \
		put_unbr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c ft_printf.h
	@cc $(FLAGS) -c $< -o $@
	@ar rcs $(NAME) $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
