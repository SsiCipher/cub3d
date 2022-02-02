/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:19:23 by yanab             #+#    #+#             */
/*   Updated: 2022/02/02 17:23:33 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Render the map matrix
void	render_map(t_data *game_data)
{
	int		i;
	int		j;
	char	*moves_count_str;
	char	*moves_str;

	moves_count_str = ft_itoa(game_data->moves);
	moves_str = ft_strjoin("Moves: ", moves_count_str);
	w_put_str(*game_data, moves_str, 20, 10);
	free(moves_str);
	free(moves_count_str);
	i = -1;
	while (game_data->map.map_matrix[++i])
	{
		j = -1;
		while (game_data->map.map_matrix[i][++j])
		{
			if (game_data->map.map_matrix[i][j] == '1')
				w_put_img(*game_data, &(game_data->wall), j, i);
			else if (game_data->map.map_matrix[i][j] == '0')
				w_put_img(*game_data, &(game_data->space), j, i);
			else if (game_data->map.map_matrix[i][j] == 'P')
				w_put_player(*game_data, &(game_data->player), j, i);
			else if (game_data->map.map_matrix[i][j] == 'E')
				w_put_img(*game_data, &(game_data->exit), j, i);
			else if (game_data->map.map_matrix[i][j] == 'C')
				w_put_img(*game_data, &(game_data->gold), j, i);
			else if (game_data->map.map_matrix[i][j] == 'D')
				w_put_img(*game_data, &(game_data->enemy), j, i);
		}
	}
}

// Handle player move event
void	move_player(t_data *data, int x, int y)
{
	char	next_block;

	mlx_clear_window(data->mlx, data->window.element);
	next_block = data->map.map_matrix[data->player.y + y][data->player.x + x];
	if (next_block == 'E')
	{
		data->gameover = data->score == 0;
		if (data->score == 0)
			w_put_str(*data, "Congrats, You've just won", 50, 50);
	}
	else
	{
		data->moves += 1;
		if (next_block == 'C')
		{
			data->score -= 1;
			next_block = '0';
		}
		else if (next_block == 'D')
		{
			data->gameover = 1;
			w_put_str(*data, "You just lost watch out", 50, 50);
		}
		data->map.map_matrix[data->player.y][data->player.x] = next_block;
		data->player.x += x;
		data->player.y += y;
		data->map.map_matrix[data->player.y][data->player.x] = 'P';
	}
	if (data->gameover == 0)
		render_map(data);
}

// key event handler
int	handle_keyevent(int keycode, t_data *data)
{
	if (keycode == K_ESC)
		exit(0);
	else if (data->gameover == 0
		&& (keycode == K_W || keycode == K_AR_U)
		&& data->map.map_matrix[data->player.y - 1][data->player.x] != '1')
	{
		data->player.img = data->player.set[P_U];
		move_player(data, 0, -1);
	}
	else if (data->gameover == 0
		&& (keycode == K_S || keycode == K_AR_D)
		&& data->map.map_matrix[data->player.y + 1][data->player.x] != '1')
	{
		data->player.img = data->player.set[P_D];
		move_player(data, 0, 1);
	}
	else if (data->gameover == 0
		&& (keycode == K_A || keycode == K_AR_L)
		&& data->map.map_matrix[data->player.y][data->player.x - 1] != '1')
	{
		data->player.img = data->player.set[P_L];
		move_player(data, -1, 0);
	}
	else if (data->gameover == 0
		&& (keycode == K_D || keycode == K_AR_R)
		&& data->map.map_matrix[data->player.y][data->player.x + 1] != '1')
	{
		data->player.img = data->player.set[P_R];
		move_player(data, 1, 0);
	}
	return (0);
}
