CC				=	cc
NAME			=	cub3d
FLAGS			=	-Wall -Wextra -Werror
DBG_FLAGS	=	-fsanitize=address -g3

INCS_DIR	= includes
LIBS_DIR	= libs
SRCS_DIR	=	src

LIBS			= libft

SRCS =	$(SRCS_DIR)/debug.c \
				$(SRCS_DIR)/error_check.c \
				$(SRCS_DIR)/init_scene.c \
				$(SRCS_DIR)/main.c \
				$(SRCS_DIR)/utils.c

all: libs $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) -I $(INCS_DIR) $(SRCS) -L $(LIBS_DIR) -l $(LIBS:lib%=%) -o $(NAME)

debug: $(SRCS)
	$(CC) $(FLAGS) $(DBG_FLAGS) -I $(INCS_DIR) $(SRCS) -L $(LIBS_DIR) -l $(LIBS:lib%=%) -o $(NAME)

libs: $(LIBS)

$(LIBS):
	make -C $(LIBS_DIR)/$@
	cp -f $(LIBS_DIR)/$@/$@.h $(INCS_DIR)
	cp -f $(LIBS_DIR)/$@/$@.a $(LIBS_DIR)

clean:
	rm -rf $(NAME)

fclean: clean
	make fclean -C $(LIBS_DIR)/libft

re: fclean all

.PHONY: all
