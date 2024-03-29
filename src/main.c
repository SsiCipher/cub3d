/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipher <cipher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:36:22 by yanab             #+#    #+#             */
/*   Updated: 2023/01/09 09:06:05 by cipher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_extension(const char *file_name)
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

void	check_args(int argc, char *argv[])
{
	if (argc != 2)
		display_error("Usage: ./cub3d <map_file.cub>\n", 1);
	else if (!is_valid_extension(argv[1]))
		display_error(
			ft_multijoin(3, "Error: file '", argv[1], "' is not .cub\n"), 1);
	else if (!file_exists(argv[1]))
		display_error(
			ft_multijoin(3, "Error: file '", argv[1], "' is not found\n"), 1);
}

int	main(int argc, char *argv[])
{
	t_global	*global;

	global = malloc(sizeof(t_global));
	if (!global)
		exit(2);
	check_args(argc, argv);
	init_global(global, argv[1]);
	free_global(global);
	return (0);
}
