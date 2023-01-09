/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:52:15 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/09 05:02:27 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calcul_indexes(t_global *var, int abs)
{
	var->P_W_D = (W_WIDTH / 2) / tan(degree_to_radian(30));
	var->P_W_H = ((DIMENSION) / (abs * SCALE)) * (var->P_W_D * SCALE);
	var->top_pixel = (W_HEIGHT / 2) - ((int)var->P_W_H / 2);
	if (var->top_pixel < 0)
		var->top_pixel = 0;
	var->bottom_pixel = (W_HEIGHT / 2) + ((int)var->P_W_H / 2);
	if (var->bottom_pixel > W_HEIGHT)
		var->bottom_pixel = W_HEIGHT;
}

void	paint_sky(t_global *var, int i)
{
	var->index = 0;
	while (var->index < var->top_pixel)
	{
		set_img_pixel(&var->mlx_img, i, var->index, var->scene->ceilling_color);
		var->index++;
	}
}

void	paint_walls(t_global *var, int i, double fov)
{
	while (var->index < var->bottom_pixel)
	{
		wall_pixels(var, fov);
		set_img_pixel(&var->mlx_img, i, var->index, var->pos);
		var->index++;
	}
}

void	draw_3d(t_global *var, int abs, int i, double fov)
{
	calcul_indexes(var, abs);
	paint_sky(var, i);
	paint_walls(var, i, fov);
	while (var->index < W_HEIGHT)
	{
		set_img_pixel(&var->mlx_img, i, var->index, var->scene->floor_color);
		var->index++;
	}
}
