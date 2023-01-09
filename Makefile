CC			= 	cc
NAME		= 	cub3d
FLAGS		= 	-Wall -Wextra -Werror -lm
DBG_FLAGS	= 	-fsanitize=address -g3
MLX_FLAGS	= 	-lmlx -framework OpenGL -framework AppKit

INCS_DIR	= 	includes
LIBS_DIR	= 	libs
SRCS_DIR	= 	src

LIBS		= 	libft

SRCS		=	$(SRCS_DIR)/parsing/debug.c \
				$(SRCS_DIR)/parsing/error_check.c \
				$(SRCS_DIR)/parsing/init_scene.c \
				$(SRCS_DIR)/parsing/utils.c \
				$(SRCS_DIR)/raycasting/rc_utils.c \
				$(SRCS_DIR)/raycasting/events.c \
				$(SRCS_DIR)/raycasting/player_casting.c \
				$(SRCS_DIR)/raycasting/player_movement.c \
				$(SRCS_DIR)/raycasting/playes_rotation.c \
				$(SRCS_DIR)/raycasting/direction.c \
				$(SRCS_DIR)/raycasting/textures.c \
				$(SRCS_DIR)/raycasting/paint_wall.c \
				$(SRCS_DIR)/raycasting/draw3D.c \
				$(SRCS_DIR)/wrappers.c \
				$(SRCS_DIR)/main.c

all: libs $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(MLX_FLAGS) -I $(INCS_DIR) $(SRCS) -L $(LIBS_DIR) -l $(LIBS:lib%=%) -o $(NAME)

debug: $(SRCS)
	$(CC) $(FLAGS) $(MLX_FLAGS) $(DBG_FLAGS) -I $(INCS_DIR) $(SRCS) -L $(LIBS_DIR) -l $(LIBS:lib%=%) -o $(NAME)

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
