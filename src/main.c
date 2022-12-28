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

int main(int argc, char *argv[])
{
	t_scene	*game_scene;

	game_scene = malloc(sizeof(t_scene *));
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
		// Read the file line by line
		// Split by space
		// Check identifier (line[0])
		// Set its value to the coresponding varibles
	}
	free(game_scene);
	return 0;
}
