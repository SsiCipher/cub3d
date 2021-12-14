/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:15:40 by yanab             #+#    #+#             */
/*   Updated: 2021/12/14 22:10:47 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Print error and exit
void	print_err(char *err)
{
	ft_printf(err);
	exit(0);
}

// Close window
int	close_window()
{
	exit(0);
	return (0);
}

// Render the map matrix
void	render_map(t_data *game_data)
{
	mlx_string_put(game_data->mlx, game_data->window.element, 20, 10, 0x00FFFFFF, ft_strjoin("Number of moves: ", ft_itoa(game_data->player_moves)));

	for (int i = 0; game_data->map.map_matrix[i]; i++)
	{
		for (int j = 0; game_data->map.map_matrix[i][j]; j++)
		{
			if (game_data->map.map_matrix[i][j] == '1')
				mlx_put_image_to_window(game_data->mlx, game_data->window.element, game_data->wall.img, j * game_data->map.scale, i * game_data->map.scale + game_data->window.padding);
			else if (game_data->map.map_matrix[i][j] == '0')
				mlx_put_image_to_window(game_data->mlx, game_data->window.element, game_data->space.img, j * game_data->map.scale, i * game_data->map.scale + game_data->window.padding);
			else if (game_data->map.map_matrix[i][j] == 'P')
			{
				if (game_data->player.x == -1)
					game_data->player.x = j;
				if (game_data->player.y == -1)
					game_data->player.y = i;
				mlx_put_image_to_window(game_data->mlx, game_data->window.element, game_data->player.img, j * game_data->map.scale, i * game_data->map.scale + game_data->window.padding);
			}
			else if (game_data->map.map_matrix[i][j] == 'E')
				mlx_put_image_to_window(game_data->mlx, game_data->window.element, game_data->exit.img, j * game_data->map.scale, i * game_data->map.scale + game_data->window.padding);
			else if (game_data->map.map_matrix[i][j] == 'C')
				mlx_put_image_to_window(game_data->mlx, game_data->window.element, game_data->collectible.img, j * game_data->map.scale, i * game_data->map.scale + game_data->window.padding);
		}
	}
}

// Handle player move event
void	move_player(t_data *data, int x, int y)
{
	data->player_moves += 1;
	if (data->map.map_matrix[data->player.y + y][data->player.x + x] == 'C')
	{
		data->score -= 1;
		data->map.map_matrix[data->player.y][data->player.x] = '0';
		data->player.x += x;
		data->player.y += y;
		data->map.map_matrix[data->player.y][data->player.x] = 'P';
	}
	else if (data->map.map_matrix[data->player.y + y][data->player.x + x] == 'E' && data->score != 0)
		return ;
	else if (data->map.map_matrix[data->player.y + y][data->player.x + x] == 'E' && data->score == 0)
	{
		mlx_clear_window(data->mlx, data->window.element);
		data->gameover = 1;
		mlx_string_put(data->mlx, data->window.element, data->window.width / 3.4, 20, 0x0050F291, "Congrats, You've just won");
		return ;
	}
	else
	{
		data->map.map_matrix[data->player.y][data->player.x] = data->map.map_matrix[data->player.y + y][data->player.x + x];
		data->player.x += x;
		data->player.y += y;
		data->map.map_matrix[data->player.y][data->player.x] = 'P';
	}
	mlx_clear_window(data->mlx, data->window.element);
	render_map(data);
}

// key event handler
int	handle_key_event(int keycode, t_data *data)
{
	if (keycode == 53) // ESC
		close_window();
	else if (data->gameover == 0 && keycode == 13 && data->map.map_matrix[data->player.y - 1][data->player.x] != '1') // Up
		move_player(data, 0, -1);
	else if (data->gameover == 0 && keycode == 2 && data->map.map_matrix[data->player.y][data->player.x + 1] != '1') // Right
		move_player(data, 1, 0);
	else if (data->gameover == 0 && keycode == 1 && data->map.map_matrix[data->player.y + 1][data->player.x] != '1') // Down
		move_player(data, 0, 1);
	else if (data->gameover == 0 && keycode == 0 && data->map.map_matrix[data->player.y][data->player.x - 1] != '1') // Left
		move_player(data, -1, 0);
	return (0);
}

int animate_game(t_data *data)
{
	static int frame = 0;
	frame++;
	if (frame == FRAMES_DURATION)
	{
		data->player.img = mlx_xpm_file_to_image(data->mlx, "./assets/player2.xpm",
			&data->player.width, &data->player.height);
	}
	if (frame == FRAMES_DURATION * 2)
	{
		data->player.img = mlx_xpm_file_to_image(data->mlx, "./assets/player.xpm",
			&data->player.width, &data->player.height);
		frame = 0;
	}
	if (data->gameover == 0)
		mlx_put_image_to_window(data->mlx, data->window.element, data->player.img, data->player.x * data->map.scale, data->player.y * data->map.scale + data->window.padding);
	return (0);
}

// Program main function
int	main(int argc, char const *argv[])
{
	int		map_fd;
	t_data	game_data;

	if (argc != 2)
		print_err("Usage: ./solong <map_file>\n");
	init_data(argv[1], &game_data);
	render_map(&game_data);
	mlx_key_hook(game_data.window.element, handle_key_event, &game_data);
	mlx_hook(game_data.window.element, 17, 0, close_window, NULL);
	mlx_loop_hook(game_data.mlx, animate_game, &game_data);
	mlx_loop(game_data.mlx);
	return (0);
}
