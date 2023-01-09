/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:34:53 by cipher            #+#    #+#             */
/*   Updated: 2023/01/09 10:21:39 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_others(t_global *global)
{
	if (global->scene->itto == 'N')
		global->pa = degree_to_radian(270);
	if (global->scene->itto == 'S')
		global->pa = degree_to_radian(90);
	if (global->scene->itto == 'E')
		global->pa = degree_to_radian(0);
	if (global->scene->itto == 'W')
		global->pa = degree_to_radian(180);
	global->key_a_d = -1;
	global->key_r_l = -1;
	global->key_u_d = -1;
	global->key_w_s = -1;
}

t_scene	*init_scene(void)
{
	t_scene	*game_scene;

	game_scene = malloc(sizeof(t_scene));
	if (!game_scene)
		exit(2);
	game_scene->north_texture.content = NULL;
	game_scene->south_texture.content = NULL;
	game_scene->west_texture.content = NULL;
	game_scene->east_texture.content = NULL;
	game_scene->floor_color = -1;
	game_scene->ceilling_color = -1;
	game_scene->map_width = 0;
	game_scene->map_height = 0;
	game_scene->map = ft_calloc(1, sizeof(char *));
	if (!game_scene->map)
		exit(2);
	game_scene->player.direction = UNSET;
	return (game_scene);
}

int	quit_game(void *params)
{
	(void)params;
	exit(0);
	return (0);
}

void	free_global(t_global *global)
{
	ft_free_arr(&global->scene->map);
	free(global->scene);
	mlx_destroy_window(global->mlx, global->mlx_win);
	mlx_destroy_image(global->mlx, global->mlx_img.content);
	mlx_destroy_image(global->mlx, global->scene->north_texture.content);
	mlx_destroy_image(global->mlx, global->scene->south_texture.content);
	mlx_destroy_image(global->mlx, global->scene->east_texture.content);
	mlx_destroy_image(global->mlx, global->scene->west_texture.content);
}

void	init_global(t_global *global, char *scene_file)
{
	int	scene_file_fd;

	scene_file_fd = open(scene_file, O_RDONLY);
	global->mlx = mlx_init();
	global->scene = init_scene();
	read_scene_file(global, scene_file_fd);
	close(scene_file_fd);
	if (check_scene_map(global->scene))
	{
		global->mlx_win = mlx_new_window(
				global->mlx, W_WIDTH, W_HEIGHT, W_TITLE);
		global->mlx_img.content = mlx_new_image(global->mlx, W_WIDTH, W_HEIGHT);
		set_img_addr(&global->mlx_img);
		set_img_addr(&global->scene->north_texture);
		set_img_addr(&global->scene->south_texture);
		set_img_addr(&global->scene->west_texture);
		set_img_addr(&global->scene->east_texture);
		init_others(global);
		mlx_hook(global->mlx_win, E_KEY_DOWN, 0, init_keys, global);
		mlx_hook(global->mlx_win, E_KEY_UP, 0, reset_keys, global);
		mlx_hook(global->mlx_win, E_DESTROY, 0, quit_game, global);
		mlx_loop_hook(global->mlx, loop_event, global);
		mlx_loop(global->mlx);
	}
}
