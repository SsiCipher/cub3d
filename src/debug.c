#include "cub3d.h"

void	debug_print_scene(t_scene *scene)
{
	printf("north_texture: [%s]\n", scene->north_texture);
	printf("south_texture: [%s]\n", scene->south_texture);
	printf("west_texture: [%s]\n", scene->west_texture);
	printf("east_texture: [%s]\n", scene->east_texture);
	printf("floor_color: [%d]\n", scene->floor_color);
	printf("ceilling_color: [%d]\n", scene->ceilling_color);
	// printf("map => width: [%ld], height: [%ld]\n", scene->map_width, scene->map_height);
	// for (int i = 0; scene->map_matrix[i]; i++)
	// 	printf("%s\n", scene->map_matrix[i]);
}
