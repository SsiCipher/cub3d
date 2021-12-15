CC = cc
NAME = solong
FLAGS = -Wall -Wextra -Werror

SRCS =	src/check_map.c \
		src/game.c \
		src/wrappers.c \
		src/init_data.c \
		main.c

LIBS = libft libftprintf libgnl

INCLUDES = $(LIBS:%=includes/%.a)

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) $(INCLUDES) $(MLX) -o $(NAME)

libs: $(LIBS)

$(LIBS):
	@make -C includes/$@
	@mv includes/$@/$@.a includes
	@echo "Done Creating > $@"

clean:
	make -C includes/libft clean
	make -C includes/libftprintf clean
	make -C includes/libgnl clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(INCLUDES)

re: fclean all

.PHONY: all
