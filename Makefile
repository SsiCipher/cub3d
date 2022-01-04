CC			=	cc
NAME		=	solong
FLAGS		=	-Wall -Wextra -Werror

SRCS		=	src/check_map.c \
				src/game.c \
				src/wrappers.c \
				src/init_data.c \
				main.c

LIBS		=	libft libftprintf libgnl

INCLUDES	=	$(LIBS:%=includes/%.a)

MLX_macos	=	-lmlx -framework OpenGL -framework AppKit
MLX_linux	=	-lmlx -lXext -lX11

all: $(LIBS) $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) $(INCLUDES) $(MLX_linux) -o $(NAME)

libs: $(LIBS)

$(LIBS):
	@make -C includes/$@
	@cp includes/$@/$@.a includes
	@echo "Done Creating > $@"

clean:
	@make -C includes/libft fclean
	@make -C includes/libftprintf fclean
	@make -C includes/libgnl fclean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(INCLUDES)

re: fclean all

.PHONY: all
