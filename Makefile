CC = cc
NAME = solong
FLAGS = -Wall -Wextra -Werror

SRCS =	src/check_map.c \
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
	@make -C includes/$@ && mv includes/$@/$@.a includes
	@make -C includes/$@ clean
	@echo "Done Creating > $@"

clean:
	rm -rf $(INCLUDES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all
