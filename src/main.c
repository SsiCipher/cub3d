/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:36:22 by yanab             #+#    #+#             */
/*   Updated: 2023/01/05 13:47:11 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_scene	*game_scene;

	game_scene = NULL;
	if (argc != 2)
		display_error("Usage: ./cub3d <map_file.cub>\n", 1);
	else if (!valid_extension(argv[1]))
		display_error(
			ft_multijoin(3, "Error: file '", argv[1], "' is not .cub\n"), 1);
	else if (!file_exists(argv[1]))
		display_error(
			ft_multijoin(3, "Error: file '", argv[1], "' is not found\n"), 1);
	else
	{
		game_scene = init_scene();
		read_scene_file(game_scene, open(argv[1], O_RDONLY));
		debug_print_scene(game_scene);
	}
	free_scene(&game_scene);
	return (0);
}
