/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:36:22 by yanab             #+#    #+#             */
/*   Updated: 2023/01/09 05:20:12 by yanab            ###   ########.fr       */
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

void	free_scene(t_scene **game_scene)
{
	ft_free_arr(&((*game_scene)->map));
	free(*game_scene);
	*game_scene = NULL;
}

int	quit_game(void *params)
{
	(void)params;
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_global	*global;

	global = malloc(sizeof(t_global));
	if (!global)
		exit(2);
	check_args(argc, argv);
	global->mlx = mlx_init();
	global->scene = init_scene();
	read_scene_file(global, open(argv[1], O_RDONLY));
	if (check_scene_map(global->scene))
	{
		global->mlx_win = mlx_new_window(global->mlx, W_WIDTH, W_HEIGHT, W_TITLE);
		global->mlx_img.content = mlx_new_image(global->mlx, W_WIDTH, W_HEIGHT);
		set_img_addr(&global->mlx_img);
		set_img_addr(&global->scene->north_texture);
		set_img_addr(&global->scene->south_texture);
		set_img_addr(&global->scene->west_texture);
		set_img_addr(&global->scene->east_texture);
		global->pa = degree_to_radian(180);
		mlx_hook(global->mlx_win, E_KEY_DOWN, 0, init_keys, global);
		mlx_hook(global->mlx_win, E_KEY_UP, 0, reset_keys, global);
		mlx_hook(global->mlx_win, E_DESTROY, 0, quit_game, global);
		mlx_loop_hook(global->mlx, loop_event, global);
		mlx_loop(global->mlx);
	}
	free_scene(&global->scene);
	return (0);
}
