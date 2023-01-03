#include "cub3d.h"

void	display_error(char *error_msg, int exit_code)
{
	if (error_msg)
		write(2, error_msg, ft_strlen(error_msg));
	exit(exit_code);
}

int	rgb_to_int(char *line)
{
	int		color;
	char	**split_line;

	split_line = ft_split(line, ',');
	color = ft_atoi(split_line[0]);
	color = (color << 8) + ft_atoi(split_line[1]);
	color = (color << 8) + ft_atoi(split_line[2]);
	ft_free_arr(&split_line);
	return (color);
}

size_t	skip_spaces(char *line, size_t start_index)
{
	size_t i = start_index;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}
