#include "cub3d.h"

bool	valid_extension(const char *file_name)
{
	return (
		!ft_strncmp(".cub", file_name + (ft_strlen(file_name) - 4), 4)
	);
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

