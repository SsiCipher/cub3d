CC			=	cc
NAME		=	cub3d
FLAGS		=	-Wall -Wextra -Werror

SRCS		=	src/main.c

LIBS		=	libft libgnl

INCLUDES	= -I includes $(LIBS:%=includes/$*/%.a)

# MLX_macos	=	-lmlx -framework OpenGL -framework AppKit
# MLX_linux	=	-lmlx -lXext -lX11

all: $(LIBS) $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) $(INCLUDES) -o $(NAME)

libs: $(LIBS)

$(LIBS):
	make -C includes/$@
	@cp includes/$@/$@.a includes

clean:
	make -C includes/libft clean
	make -C includes/libgnl clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(INCLUDES)
	make -C includes/libft fclean
	make -C includes/libgnl fclean

re: fclean all

.PHONY: all
