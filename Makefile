CC			=	cc
NAME		=	so_long
FLAGS		=	-Wall -Wextra -Werror

SRCS		=	src/check_map.c \
				src/game.c \
				src/wrappers.c \
				src/init_data.c \
				so_long.c

LIBS		=	libft libgnl

INCLUDES	=	$(LIBS:%=includes/$*/%.a)

MLX_macos	=	-lmlx -framework OpenGL -framework AppKit
MLX_linux	=	-lmlx -lXext -lX11

all: $(LIBS) $(NAME)

$(NAME): $(SRCS)
	$(CC) -I includes $(SRCS) $(INCLUDES) $(MLX_macos) -o $(NAME)

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