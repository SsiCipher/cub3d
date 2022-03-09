/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:53:26 by yanab             #+#    #+#             */
/*   Updated: 2022/03/09 01:30:26 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Put image to window in (x, y)
void	w_put_img(t_data data, t_img *image, int x, int y)
{
	mlx_put_image_to_window(data.mlx, data.window.element, image->img,
		x * data.map.scale, y * data.map.scale + data.window.padding);
}

// Put player to window in (x, y) and set variables
void	w_put_player(t_data data, t_player *player, int x, int y)
{
	if (player->x == -1)
		player->x = x;
	if (player->y == -1)
		player->y = y;
	mlx_put_image_to_window(data.mlx, data.window.element, player->img,
		x * data.map.scale, y * data.map.scale + data.window.padding);
}

// Put string to window in (x, y)
void	w_put_str(t_data data, char *str, int x, int y)
{
	mlx_string_put(data.mlx, data.window.element, x, y, 0x00FFFFFF, str);
}

// Read player image
void	*xpm_to_img_p(t_data data, char const *filename, t_player *player)
{
	char	*path;
	void	*img_p;

	path = ft_strjoin("./assets/", filename);
	img_p = mlx_xpm_file_to_image(data.mlx, path,
			&(player->width), &(player->height));
	free(path);
	return (img_p);
}

// Read normal image
void	*xpm_to_img_i(t_data data, char const *filename, t_img *img)
{
	char	*path;
	void	*img_p;

	path = ft_strjoin("./assets/", filename);
	img_p = mlx_xpm_file_to_image(data.mlx, path,
			&(img->width), &(img->height));
	free(path);
	return (img_p);
}
