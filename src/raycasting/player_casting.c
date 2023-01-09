/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:09:27 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/09 04:11:00 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_wall(t_global *var, double fov, int i)
{
	double	abs;

	while (1)
	{
		var->Xhitwall += cos(fov);
		var->Yhitwall += sin(fov);
		if (var->scene->map[(int)(var->Yhitwall) / DIMENSION]
			[(int)(var->Xhitwall) / DIMENSION] == '1'
			|| var->scene->map[(int)(var->Yhitwall + sin(fov)) / DIMENSION]
			[(int)(var->Xhitwall - cos(fov)) / DIMENSION] == '1'
			|| var->scene->map[(int)(var->Yhitwall - sin(fov)) / DIMENSION]
			[(int)(var->Xhitwall + cos(fov)) / DIMENSION] == '1'
			|| var->scene->map[(int)(var->Yhitwall + sin(fov)) / DIMENSION]
			[(int)(var->Xhitwall + cos(fov)) / DIMENSION] == '1'
			|| var->scene->map[(int)(var->Yhitwall - sin(fov)) / DIMENSION]
			[(int)(var->Xhitwall - cos(fov)) / DIMENSION] == '1')
		{
			direction_option(var, var->Xhitwall, var->Yhitwall, fov);
			abs = sqrt(pow((var->Xhitwall - (var->scene->player.x \
			* DIMENSION)), 2) + pow((var->Yhitwall - (var->scene->player.y \
			* DIMENSION)), 2)) * cos(var->pa - fov);
			draw_3d(var, abs, i, fov);
			return ;
		}
	}
}

void	far_wall(t_global *var, double fov, int i)
{
	double	yf;
	double	yc;
	int		speed;

	speed = 30;
	while (1)
	{
		var->Xhitwall += cos(fov) * speed;
		var->Yhitwall += sin(fov) * speed;
		yf = sin(fov) * speed;
		yc = sin(fov);
		if (var->scene->map[(int)(var->Yhitwall) / DIMENSION]
			[(int)(var->Xhitwall) / DIMENSION] == '1'
			|| var->scene->map[(int)(var->Yhitwall + yc + yf) / DIMENSION]
			[(int)(var->Xhitwall - cos(fov) + (cos(fov) * speed)) \
			/ DIMENSION] == '1'
			|| var->scene->map[(int)(var->Yhitwall - yc - yf) / DIMENSION]
			[(int)(var->Xhitwall + cos(fov) + (cos(fov) * speed)) \
			/ DIMENSION] == '1'
			|| var->scene->map[(int)(var->Yhitwall - yc + yf) / DIMENSION]
			[(int)(var->Xhitwall + cos(fov) - (cos(fov) * speed)) \
			/ DIMENSION] == '1'
			||var->scene->map[(int)(var->Yhitwall + yc - yf) / DIMENSION]
			[(int)(var->Xhitwall - cos(fov) - (cos(fov) * speed)) \
			/ DIMENSION] == '1')
		{
			close_wall(var, fov, i);
			return ;
		}
	}
}

void	ray_projection(double fov, t_global *var, int i)
{
	var->Xhitwall = var->scene->player.x * DIMENSION;
	var->Yhitwall = var->scene->player.y * DIMENSION;
	far_wall(var, fov, i);
}

double	normalize_angle(double angle)
{
	angle = remainder(angle, M_PI * 2);
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void	player_view(t_global *var)
{
	int		i;
	double	fov;

	i = -1;
	fov = var->pa - (30 * (M_PI / 180));
	while (++i < W_WIDTH)
	{
		ray_projection(normalize_angle(fov), var, i);
		fov += (degree_to_radian(60)) / (W_WIDTH);
	}
}
