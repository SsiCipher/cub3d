/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:19:23 by yanab             #+#    #+#             */
/*   Updated: 2022/03/09 02:12:53 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Put the right image based on the char
void	put_image(char map_char, t_data *game_data, int x, int y)
{
	if (map_char == '1')
		w_put_img(*game_data, &(game_data->wall), x, y);
	else if (map_char == '0')
		w_put_img(*game_data, &(game_data->space), x, y);
	else if (map_char == 'P')
		w_put_player(*game_data, &(game_data->player), x, y);
	else if (map_char == 'E')
		w_put_img(*game_data, &(game_data->exit), x, y);
	else if (map_char == 'C')
		w_put_img(*game_data, &(game_data->gold), x, y);
}

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
			put_image(game_data->map.map_matrix[i][j], game_data, j, i);
	}
}

// move the player in matrix
void	decide_move(t_data *data, char next_block, int x, int y)
{
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
		data->map.map_matrix[data->player.y][data->player.x] = next_block;
		data->player.x += x;
		data->player.y += y;
		data->map.map_matrix[data->player.y][data->player.x] = 'P';
	}
}

// Handle player movement
void	move_player(t_data *data, int x, int y)
{
	char	next_block;

	next_block = data->map.map_matrix[data->player.y + y][data->player.x + x];
	if (next_block == '1')
		return ;
	mlx_clear_window(data->mlx, data->window.element);
	decide_move(data, next_block, x, y);
	if (data->gameover == 0)
		render_map(data);
}

// key event handler
int	handle_keyevent(int keycode, t_data *data)
{
	if (keycode == K_ESC)
		exit(0);
	else if (data->gameover == 0 && keycode == K_W)
	{
		data->player.img = data->player.set[P_U];
		move_player(data, 0, -1);
	}
	else if (data->gameover == 0 && keycode == K_S)
	{
		data->player.img = data->player.set[P_D];
		move_player(data, 0, 1);
	}
	else if (data->gameover == 0 && keycode == K_A)
	{
		data->player.img = data->player.set[P_L];
		move_player(data, -1, 0);
	}
	else if (data->gameover == 0 && keycode == K_D)
	{
		data->player.img = data->player.set[P_R];
		move_player(data, 1, 0);
	}
	return (0);
}
