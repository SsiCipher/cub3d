CC			=	cc
NAME		=	cub3d
FLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g3

SRCS		=	src/main.c

LIBS		=	libft

INCLUDES	= $(LIBS:%=includes/$*/%.a)

# MLX_macos	=	-lmlx -framework OpenGL -framework AppKit
# MLX_linux	=	-lmlx -lXext -lX11

all: $(LIBS) $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) -I includes $(SRCS) $(INCLUDES) -o $(NAME)

libs: $(LIBS)

$(LIBS):
	make -C includes/$@
	@cp includes/$@/$@.a includes

clean:
	make -C includes/libft clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(INCLUDES)
	make -C includes/libft fclean

re: fclean all

.PHONY: all
