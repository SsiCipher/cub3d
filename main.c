/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:15:40 by yanab             #+#    #+#             */
/*   Updated: 2021/12/14 17:49:22 by yanab            ###   ########.fr       */
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
	for (int i = 0; game_data->map.map_matrix[i]; i++)
	{
		for (int j = 0; game_data->map.map_matrix[i][j]; j++)
		{
			if (game_data->map.map_matrix[i][j] == '1')
				mlx_put_image_to_window(game_data->mlx, game_data->window.elememt, game_data->wall.img, j * game_data->map.scale, i * game_data->map.scale);
			else if (game_data->map.map_matrix[i][j] == '0')
				mlx_put_image_to_window(game_data->mlx, game_data->window.elememt, game_data->space.img, j * game_data->map.scale, i * game_data->map.scale);
			else if (game_data->map.map_matrix[i][j] == 'P')
			{
				if (game_data->player.x == -1)
					game_data->player.x = j;
				if (game_data->player.y == -1)
					game_data->player.y = i;
				mlx_put_image_to_window(game_data->mlx, game_data->window.elememt, game_data->player.img, j * game_data->map.scale, i * game_data->map.scale);
			}
			else if (game_data->map.map_matrix[i][j] == 'E')
				mlx_put_image_to_window(game_data->mlx, game_data->window.elememt, game_data->exit.img, j * game_data->map.scale, i * game_data->map.scale);
			else if (game_data->map.map_matrix[i][j] == 'C')
				mlx_put_image_to_window(game_data->mlx, game_data->window.elememt, game_data->collectible.img, j * game_data->map.scale, i * game_data->map.scale);
		}
	}
}

// Handle player move event
void	move_player(t_data *data, int x, int y)
{
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
		mlx_clear_window(data->mlx, data->window.elememt);
		mlx_string_put(data->mlx, data->window.elememt, data->window.width / 4, data->window.height / 2, 255, "Congrats, You've just won");
		return ;
	}
	else
	{
		data->map.map_matrix[data->player.y][data->player.x] = data->map.map_matrix[data->player.y + y][data->player.x + x];
		data->player.x += x;
		data->player.y += y;
		data->map.map_matrix[data->player.y][data->player.x] = 'P';
	}
	mlx_clear_window(data->mlx, data->window.elememt);
	render_map(data);
	printf("Move Player Right to (%d, %d)\n", data->player.x, data->player.y);
}

// key event handler
int	handle_key_event(int keycode, t_data *data)
{
	// printf("Keycode: %d\n", keycode);
	if (keycode == 53) // ESC
		close_window();
	else if (keycode == 13 && data->map.map_matrix[data->player.y - 1][data->player.x] != '1') // Up
	{
		move_player(data, 0, -1);
	}
	else if (keycode == 2 && data->map.map_matrix[data->player.y][data->player.x + 1] != '1') // Right
	{
		move_player(data, 1, 0);
	}
	else if (keycode == 1 && data->map.map_matrix[data->player.y + 1][data->player.x] != '1') // Down
	{
		move_player(data, 0, 1);
	}
	else if (keycode == 0 && data->map.map_matrix[data->player.y][data->player.x - 1] != '1') // Left
	{
		move_player(data, -1, 0);
	}

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

	printf("Score: %d\n", game_data.score);

	render_map(&game_data);

	printf("Player is in [%d, %d]\n", game_data.player.x, game_data.player.y);

	mlx_key_hook(game_data.window.elememt, handle_key_event, &game_data);
	mlx_hook(game_data.window.elememt, 17, 0, close_window, NULL);
	mlx_loop(game_data.mlx);
	return (0);
}
