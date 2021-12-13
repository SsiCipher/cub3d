CC = cc
NAME = solong
FLAGS = -Wall -Wextra -Werror

SRCS =	src/check_map.c \
		main.c

LIBS = libft libftprintf libgnl

INCLUDES = $(LIBS:%=includes/%.a)

all: $(NAME)
	@printf ""

$(NAME): $(SRCS)
	@$(CC) $(SRCS) $(INCLUDES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

debug: $(SRCS)
	@$(CC) $(SRCS) $(INCLUDES) -g -lmlx -framework OpenGL -framework AppKit -o $(NAME)

libs: $(LIBS)

$(LIBS):
	@make -C includes/$@
	@make -C includes/$@ clean
	@mv includes/$@/$@.a includes
	@echo "Done Creating > $@"

test: all
	./solong
	@echo "\n"
	./solong maps/bad_border_map.ber
	@echo "\n"
	./solong maps/bad_shape_map.ber
	@echo "\n"
	./solong maps/empty_map.ber
	@echo "\n"
	./solong maps/invalid_chars_map.ber
	@echo "\n"
	./solong maps/missing_chars_map.ber
	@echo "\n"
	./solong maps/valid_map.ber
	@echo "\n"
	./solong maps/valid_map2.ber
	@echo "\n"

clean:
	@rm -rf $(INCLUDES)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all
