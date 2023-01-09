/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 04:18:04 by yanab             #+#    #+#             */
/*   Updated: 2023/01/09 04:19:31 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_img_addr(t_img *image)
{
	image->addr = mlx_get_data_addr(
			image->content,
			&image->bits_per_pixel,
			&image->line_length,
			&image->endian);
}

void	set_img_pixel(t_img *mlx_img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > W_WIDTH || y < 0 || y > W_HEIGHT)
		return ;
	dst = mlx_img->addr +(
			y * mlx_img->line_length + x * (mlx_img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
