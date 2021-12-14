#include "../so_long.h"

// Count the occurences of a char in str
int	count_char(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str++ == c)
			count++;
	}
	return (count);
}

// Create game matrix
void	create_map_matrix(char const *map_filename, t_map *map, t_data *data)
{
	int		map_fd;
	char	*map_line;

	map_fd = open(map_filename, O_RDONLY);
	if (map_fd < 0)
		print_err("Error: Map file not found!\n");
	while ((map_line = get_next_line(map_fd)) != NULL)
	{
		map->height += 1;
		map->map_matrix = ft_realloc(
				map->map_matrix, sizeof(char *) * map->height, sizeof(char *) * (map->height + 1));
		if (!map->map_matrix)
			print_err("Error: There isn't enough memory to allocate\n");
		if (map->width != -1 && map->width != ft_strlen(map_line))
			print_err("Error: The provided map is not a valid map.\n");
		map->map_matrix[map->height - 1] = ft_strdup(map_line);
		data->score += count_char(map_line, 'C');
		if (!map->map_matrix[map->height - 1])
			print_err("Error: There isn't enough memory to allocate\n");
		if (map->width == -1)
			map->width = ft_strlen(map_line);
	}
	if (map->map_matrix != NULL)
		map->map_matrix[map->height] = NULL;
}

// Check if the map matrix is valid
void	check_map_matrix(t_map map)
{
	if (
		!check_map_shape(map)
		|| !check_map_border(map)
		|| !check_map_characters(map)
	)
		print_err("Error: The provided map is not a valid map.\n");
}

// Set initial values of the map
void	init_map(t_map *map, int scale)
{
	map->width = -1;
	map->height = 0;
	map->scale = scale;
	map->map_matrix = NULL;
}

// Init game data
void	init_data(const char *map_filename, t_data *data)
{
	data->mlx = mlx_init();
	init_map(&(data->map), 10);
	data->score = 0;
	create_map_matrix(map_filename, &(data->map), data);
	check_map_matrix(data->map);

	data->wall.img = mlx_xpm_file_to_image(data->mlx, "./assets/wall.xpm", &data->wall.width, &data->wall.height);
	data->space.img = mlx_xpm_file_to_image(data->mlx, "./assets/space.xpm", &data->space.width, &data->space.height);
	data->player.img = mlx_xpm_file_to_image(data->mlx, "./assets/player.xpm", &data->player.width, &data->player.height);
	data->player.x = -1;
	data->player.y = -1;
	data->collectible.img = mlx_xpm_file_to_image(data->mlx, "./assets/collectible.xpm", &data->collectible.width, &data->collectible.height);
	data->exit.img = mlx_xpm_file_to_image(data->mlx, "./assets/exit.xpm", &data->exit.width, &data->exit.height);

	data->map.scale = data->wall.width;
	data->window.width = data->map.width * data->map.scale;
	data->window.height = data->map.height * data->map.scale;
	data->window.elememt = mlx_new_window(data->mlx, data->window.width, data->window.height, "So Freaking Long (But it's good tho)");
}
