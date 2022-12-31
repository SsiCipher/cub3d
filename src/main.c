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
	game_scene->floor_color = -1;
	game_scene->ceilling_color = -1;
	game_scene->map_width = 0;
	game_scene->map_height = 0;
	game_scene->map_matrix = NULL;
}

int	rgb_to_int(char *line)
{
	char	**split_line;
	int		color;

	split_line = ft_split(line, ',');
	color = ft_atoi(split_line[0]);
	color = (color << 8) + ft_atoi(split_line[1]);
	color = (color << 8) + ft_atoi(split_line[2]);
	for (int i = 0; split_line[i]; i++)
		free(split_line[i]);
	free(split_line);
	return (color);
}

size_t	skip_spaces(char *line, size_t start_index)
{
	size_t i = start_index;
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

void	read_scene_map(t_scene *game_scene, int scene_file_fd)
{
	char *line;

	(void)game_scene;
	line = ft_getline(scene_file_fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		printf("%s\n", line);
		free(line);
		line = ft_getline(scene_file_fd);
	}
}

void	read_scene(t_scene *game_scene, int scene_file_fd)
{
	char *line;

	line = ft_getline(scene_file_fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (*(line + skip_spaces(line, 0)) == '1')
			read_scene_map(game_scene, scene_file_fd);
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
		free(line);
		line = ft_getline(scene_file_fd);
	}
}

void	debug_print_scene(t_scene *game_scene)
{
	printf("north_texture: %s\n", game_scene->north_texture);
	printf("south_texture: %s\n", game_scene->south_texture);
	printf("west_texture: %s\n", game_scene->west_texture);
	printf("east_texture: %s\n", game_scene->east_texture);
	printf("floor_color: %d\n", game_scene->floor_color);
	printf("ceilling_color: %d\n", game_scene->ceilling_color);
}

void	free_scene(t_scene **game_scene)
{
	free((*game_scene)->north_texture);
	free((*game_scene)->south_texture);
	free((*game_scene)->west_texture);
	free((*game_scene)->east_texture);
	if ((*game_scene)->map_matrix)
		ft_free_arr(&((*game_scene)->map_matrix));
	free(*game_scene);
	*game_scene = NULL;
}

int	main(int argc, char *argv[])
{
	t_scene	*game_scene;

	game_scene = malloc(sizeof(t_scene));
	if (!game_scene)
		return (EXIT_FAILURE);
	if (argc != 2)
		{printf("Usage: ./cub3d <map_file.cub>\n");exit(1);}
	else if (!valid_extension(argv[1]))
		{printf("Error: the file needs to be a .cub file\n");exit(1);}
	else if (!file_exists(argv[1]))
		{printf("Error: unable to open file %s\n", argv[1]);exit(1);}
	else
	{
		init_scene(game_scene);
		read_scene(game_scene, open(argv[1], O_RDONLY));
		debug_print_scene(game_scene);
		// Split by space
		// Check identifier (line[0])
		// Set its value to the coresponding varibles
	}
	free_scene(&game_scene);
	return 0;
}
