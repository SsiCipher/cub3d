/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:13:47 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/09 08:54:32 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_right(t_global *var)
{
	double	delta_x;
	double	delta_y;

	delta_x = cos((var->pa + (M_PI / 2))) * (-SPEED - (SIGHT_SPEED));
	delta_y = sin((var->pa + (M_PI / 2))) * (-SPEED - (SIGHT_SPEED));
	if (var->scene->map[(int)(var->scene->player.y - delta_y)] \
	[(int)(var->scene->player.x - delta_x)] != '0'
	|| var->scene->map[(int)(var->scene->player.y)] \
	[(int)(var->scene->player.x - delta_x)] != '0'
	|| var->scene->map[(int)(var->scene->player.y - delta_y)] \
	[(int)(var->scene->player.x)] != '0')
		return ;
	var->scene->player.x -= delta_x;
	var->scene->player.y -= delta_y;
}

void	ft_left(t_global *var)
{
	double	delta_x;
	double	delta_y;

	delta_x = cos((var->pa - (M_PI / 2))) * (SPEED + SIGHT_SPEED);
	delta_y = sin((var->pa - (M_PI / 2))) * (SPEED + SIGHT_SPEED);
	if (var->scene->map[(int)(var->scene->player.y + delta_y)] \
	[(int)(var->scene->player.x + delta_x)] == '1'
	|| var->scene->map[(int)(var->scene->player.y)] \
	[(int)(var->scene->player.x + delta_x)] == '1'
	|| var->scene->map[(int)(var->scene->player.y + delta_y)] \
	[(int)(var->scene->player.x)] == '1')
		return ;
	var->scene->player.y += delta_y;
	var->scene->player.x += delta_x;
}

void	ft_down(t_global *var)
{
	double	delta_x;
	double	delta_y;

	delta_x = cos(var->pa) * (SPEED + (SIGHT_SPEED));
	delta_y = sin(var->pa) * (SPEED + (SIGHT_SPEED));
	if (var->scene->map[(int)(var->scene->player.y + delta_y)] \
	[(int)(var->scene->player.x + delta_x)] != '0'
	|| var->scene->map[(int)(var->scene->player.y)] \
	[(int)(var->scene->player.x + delta_x)] != '0'
	|| var->scene->map[(int)(var->scene->player.y + delta_y)] \
	[(int)(var->scene->player.x)] != '0')
		return ;
	var->scene->player.x += delta_x;
	var->scene->player.y += delta_y;
}

void	ft_up(t_global *var)
{
	double	delta_x;
	double	delta_y;

	delta_x = cos(var->pa) * (SPEED + (SIGHT_SPEED));
	delta_y = sin(var->pa) * (SPEED + (SIGHT_SPEED));
	if (var->scene->map[(int)(var->scene->player.y - delta_y)] \
	[(int)(var->scene->player.x - delta_x)] != '0'
	|| var->scene->map[(int)(var->scene->player.y)] \
	[(int)(var->scene->player.x - delta_x)] != '0'
	|| var->scene->map[(int)(var->scene->player.y - delta_y)] \
	[(int)(var->scene->player.x)] != '0')
		return ;
	var->scene->player.x -= delta_x;
	var->scene->player.y -= delta_y;
}
