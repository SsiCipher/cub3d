#include "cub3d.h"

void	init_scene(t_scene *game_scene)
{
	game_scene->north_texture = NULL;
	game_scene->south_texture = NULL;
	game_scene->west_texture = NULL;
	game_scene->east_texture = NULL;
	game_scene->floor_color = -1;
	game_scene->ceilling_color = -1;
	game_scene->map_width = 0;
	game_scene->map_height = 0;
	game_scene->map_matrix = ft_calloc(1, sizeof(char *));
	if (!game_scene->map_matrix)
		exit(1);
}

void	free_scene(t_scene **game_scene)
{
	free((*game_scene)->north_texture);
	free((*game_scene)->south_texture);
	free((*game_scene)->west_texture);
	free((*game_scene)->east_texture);
	ft_free_arr(&((*game_scene)->map_matrix));
	free(*game_scene);
	*game_scene = NULL;
}

void	add_scene_element(t_scene *scene, char *scene_line)
{

}

void	read_scene_file(t_scene *scene, int scene_file_fd)
{
	char	*line;
	size_t	start_spaces;
	// char	identifiers[7] = {"NO", "SO", "WE", "EA", "F", "C", NULL};

	(void)scene;
	line = ft_getline(scene_file_fd);
	while (line)
	{
		start_spaces = skip_spaces(line, 0);
		if (line[start_spaces] == '1')
		if (!ft_strncmp(line + start_spaces, "NO ", 3))
			printf("%s", line);
		free(line);
		line = ft_getline(scene_file_fd);
	}
}

void	_read_scene_file(t_scene *game_scene, int scene_file_fd)
{
	char *line;

	line = ft_getline(scene_file_fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		// if (*(line + skip_spaces(line, 0)) == '1')
		// 	read_scene_map(game_scene, scene_file_fd, line);
		else if (!ft_strncmp(line, "NO ", 3))
		{
			if (game_scene->north_texture)
				{printf("Error: north_texture is duplicated\n");exit(1);}
			game_scene->north_texture = ft_strdup(line + skip_spaces(line, 3));
		}
		else if (!ft_strncmp(line, "SO ", 3))
		{
			if (game_scene->south_texture)
				{printf("Error: south_texture is duplicated\n");exit(1);}
			game_scene->south_texture = ft_strdup(line + skip_spaces(line, 3));
		}
		else if (!ft_strncmp(line, "WE ", 3))
		{
			if (game_scene->west_texture)
				{printf("Error: west_texture is duplicated\n");exit(1);}
			game_scene->west_texture = ft_strdup(line + skip_spaces(line, 3));
		}
		else if (!ft_strncmp(line, "EA ", 3))
		{
			if (game_scene->east_texture)
				{printf("Error: east_texture is duplicated\n");exit(1);}
			game_scene->east_texture = ft_strdup(line + skip_spaces(line, 3));
		}
		else if (!ft_strncmp(line, "F ", 2))
		{
			if (game_scene->floor_color != -1)
				{printf("Error: floor_color is duplicated\n");exit(1);}
			game_scene->floor_color = rgb_to_int(line + skip_spaces(line, 2));
		}
		else if (!ft_strncmp(line, "C ", 2))
		{
			if (game_scene->ceilling_color != -1)
				{printf("Error: ceilling_color is duplicated\n");exit(1);}
			game_scene->ceilling_color = rgb_to_int(line + skip_spaces(line, 2));
		}
		else if (!ft_isempty(line))
			{printf("Error: the map contains invalid identifier\n");exit(1);}
		free(line);
		line = ft_getline(scene_file_fd);
	}
}

