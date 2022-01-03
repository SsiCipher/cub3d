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

MLX			=	-lmlx -framework OpenGL -framework AppKit

all: $(LIBS) $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) $(INCLUDES) $(MLX) -o $(NAME)

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
