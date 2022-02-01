/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:53:26 by yanab             #+#    #+#             */
/*   Updated: 2022/02/01 15:51:09 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Put image to window in (x, y)
void	w_put_img(t_data data, t_img *image, int x, int y)
{
	if (image->x == -1)
		image->x = x;
	if (image->y == -1)
		image->y = y;
	mlx_put_image_to_window(data.mlx, data.window.element, image->img,
		x * data.map.scale, y * data.map.scale + data.window.padding);
}

// Put string to window in (x, y)
void	w_put_str(t_data data, char *str, int x, int y)
{
	mlx_string_put(data.mlx, data.window.element, x, y, 0x00FFFFFF, str);
}
