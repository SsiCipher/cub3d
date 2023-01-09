/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:53:32 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/09 04:11:06 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_pixels(t_global *var, double fov)
{
	if (var->direction == 'N')
	{
		x_wall_text(var, fov, var->scene->north_texture.line_length);
		north_wall(var);
	}
	if (var->direction == 'S')
	{
		x_wall_text(var, fov, var->scene->south_texture.line_length);
		south_wall(var);
	}
	if (var->direction == 'W')
	{
		x_wall_text(var, fov, var->scene->west_texture.line_length);
		west_wall(var);
	}
	if (var->direction == 'E')
	{
		x_wall_text(var, fov, var->scene->east_texture.line_length);
		east_wall(var);
	}
}

void	x_wall_text(t_global *var, double fov, int line)
{
	if (var->scene->map[(int)(var->Yhitwall + sin(fov)) / DIMENSION] \
	[(int)(var->Xhitwall - cos(fov)) / DIMENSION] == '1')
		var->x_text = (int)var->Xhitwall % (line / 4);
	else
		var->x_text = (int)var->Yhitwall % (line / 4);
	if (line / 4 > DIMENSION)
		var->x_text = ((int)var->x_text * (line / 4) / DIMENSION % (line / 4));
}
