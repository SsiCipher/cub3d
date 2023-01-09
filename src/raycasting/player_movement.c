/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:13:47 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/09 04:11:02 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_right(t_global *var)
{
	double	deltaX;
	double	deltaY;

	deltaX = cos((var->pa + (M_PI / 2))) * (-SPEED - (SIGHT_SPEED));
	deltaY = sin((var->pa + (M_PI / 2))) * (-SPEED - (SIGHT_SPEED));
	if (var->scene->map[(int)(var->scene->player.y - deltaY)] \
	[(int)(var->scene->player.x - deltaX)] != '0'
	|| var->scene->map[(int)(var->scene->player.y)] \
	[(int)(var->scene->player.x - deltaX)] != '0'
	|| var->scene->map[(int)(var->scene->player.y - deltaY)] \
	[(int)(var->scene->player.x)] != '0')
		return ;
	var->scene->player.x -= deltaX;
	var->scene->player.y -= deltaY;
}

void	ft_left(t_global *var)
{
	double	deltaX;
	double	deltaY;

	deltaX = cos((var->pa - (M_PI / 2))) * (SPEED + SIGHT_SPEED);
	deltaY = sin((var->pa - (M_PI / 2))) * (SPEED + SIGHT_SPEED);
	if (var->scene->map[(int)(var->scene->player.y + deltaY)] \
	[(int)(var->scene->player.x + deltaX)] == '1'
	|| var->scene->map[(int)(var->scene->player.y)] \
	[(int)(var->scene->player.x + deltaX)] == '1'
	|| var->scene->map[(int)(var->scene->player.y + deltaY)] \
	[(int)(var->scene->player.x)] == '1')
		return ;
	var->scene->player.y += deltaY;
	var->scene->player.x += deltaX;
}

void	ft_down(t_global *var)
{
	double	deltaX;
	double	deltaY;

	deltaX = cos(var->pa) * (SPEED + (SIGHT_SPEED));
	deltaY = sin(var->pa) * (SPEED + (SIGHT_SPEED));
	if (var->scene->map[(int)(var->scene->player.y + deltaY)] \
	[(int)(var->scene->player.x + deltaX)] != '0'
	|| var->scene->map[(int)(var->scene->player.y)] \
	[(int)(var->scene->player.x + deltaX)] != '0'
	|| var->scene->map[(int)(var->scene->player.y + deltaY)] \
	[(int)(var->scene->player.x)] != '0')
		return ;
	var->scene->player.x += deltaX;
	var->scene->player.y += deltaY;
}

void	ft_up(t_global *var)
{
	double	deltaX;
	double	deltaY;

	deltaX = cos(var->pa) * (SPEED + (SIGHT_SPEED));
	deltaY = sin(var->pa) * (SPEED + (SIGHT_SPEED));
	if (var->scene->map[(int)(var->scene->player.y - deltaY)] \
	[(int)(var->scene->player.x - deltaX)] != '0'
	|| var->scene->map[(int)(var->scene->player.y)] \
	[(int)(var->scene->player.x - deltaX)] != '0'
	|| var->scene->map[(int)(var->scene->player.y - deltaY)] \
	[(int)(var->scene->player.x)] != '0')
		return ;
	var->scene->player.x -= deltaX;
	var->scene->player.y -= deltaY;
}
