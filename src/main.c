#include "cub3d.h"

bool	valid_extension(const char *file_name)
{
	return (ft_strncmp(".cub", file_name + (ft_strlen(file_name) - 4), 4) == 0);
}

bool	file_exists(const char *file_name)
{
	int		file_fd;
	bool	file_exists;

	file_fd = open(file_name, O_RDONLY);
	file_exists = file_fd != -1;
	if (file_exists)
		close(file_fd);
	return (file_exists);
}

void	init_scene(t_scene *game_scene)
{
	game_scene->north_texture = NULL;
	game_scene->south_texture = NULL;
	game_scene->west_texture = NULL;
	game_scene->east_texture = NULL;
	game_scene->floor_color = 0x000000;
	game_scene->ceilling_color = 0x000000;
	game_scene->map_width = 0;
	game_scene->map_height = 0;
	game_scene->map_matrix = NULL;
}

int rgb_to_int(char *line)
{
	char **split_line = ft_split(line, ',');

	int r = ft_atoi(split_line[0]);
	int g = ft_atoi(split_line[1]);
	int b = ft_atoi(split_line[2]);
	for (int i = 0; split_line[i]; i++)
		free(split_line[i]);
	return (r << 16 | g << 8 | b);
}

size_t skip_spaces(char *line, size_t start_index)
{
	size_t i = start_index;
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

void	read_scene(t_scene *game_scene, int scene_file_fd)
{
	char *line;

	line = get_next_line(scene_file_fd);
	while (line)
	{
		if (!ft_strncmp(split_line[0], "NO", 3))
			game_scene->north_texture = ft_strdup(split_line[1]);
		else if (!ft_strncmp(split_line[0], "SO", 3))
			game_scene->south_texture = ft_strdup(split_line[1]);
		else if (!ft_strncmp(split_line[0], "WE", 3))
			game_scene->west_texture = ft_strdup(split_line[1]);
		else if (!ft_strncmp(split_line[0], "EA", 3))
			game_scene->east_texture = ft_strdup(split_line[1]);
		else if (!ft_strncmp(split_line[0], "F", 2))
			game_scene->floor_color = rgb_to_int(split_line[1]);
		else if (!ft_strncmp(split_line[0], "C", 2))
			game_scene->ceilling_color = rgb_to_int(split_line[1]);

		for (int i = 0; split_line[i]; i++)
			free(split_line[i]);
		free(line);
		line = get_next_line(scene_file_fd);
	}
}

int main(int argc, char *argv[])
{
	t_scene	*game_scene;

	game_scene = malloc(sizeof(t_scene));
	if (!game_scene)
		return (EXIT_FAILURE);
	if (argc != 2)
		printf("Usage: ./cub3d <map_file.cub>\n");
	else if (!valid_extension(argv[1]))
		printf("Error: the file needs to be a .cub file\n");
	else if (!file_exists(argv[1]))
		printf("Error: unable to open file %s\n", argv[1]);
	else
	{
		init_scene(game_scene);
		read_scene(game_scene, open(argv[1], O_RDONLY));
		printf("%d\n", game_scene->ceilling_color);
		// Read the file line by line
		// Split by space
		// Check identifier (line[0])
		// Set its value to the coresponding varibles
	}
	free(game_scene);
	return 0;
}
