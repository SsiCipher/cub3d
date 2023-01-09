/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:51:53 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/09 08:22:29 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	north_wall(t_global *var)
{
	t_img	texture;
	int		fixed_point;

	texture = var->scene->north_texture;
	fixed_point = var->index + (var->p_w_h / 2) - (W_HEIGHT / 2);
	var->y_text = fixed_point * ((double)(texture.line_length / 4)
			/ var->p_w_h);
	var->pos = *((unsigned int *)texture.addr + var->y_text
			* (texture.line_length / 4) + var->x_text);
}

void	south_wall(t_global *var)
{
	t_img	texture;
	int		fixed_point;

	texture = var->scene->south_texture;
	fixed_point = var->index + (var->p_w_h / 2) - (W_HEIGHT / 2);
	var->y_text = fixed_point * ((double)(texture.line_length / 4)
			/ var->p_w_h);
	var->pos = *((unsigned int *)texture.addr + var->y_text
			* (texture.line_length / 4) + var->x_text);
}

void	west_wall(t_global *var)
{
	t_img	texture;
	int		fixed_point;

	texture = var->scene->west_texture;
	fixed_point = var->index + (var->p_w_h / 2) - (W_HEIGHT / 2);
	var->y_text = fixed_point * ((double)(texture.line_length / 4)
			/ var->p_w_h);
	var->pos = *((unsigned int *)texture.addr + var->y_text
			* (texture.line_length / 4) + var->x_text);
}

void	east_wall(t_global *var)
{
	t_img	texture;
	int		fixed_point;

	texture = var->scene->east_texture;
	fixed_point = var->index + (var->p_w_h / 2) - (W_HEIGHT / 2);
	var->y_text = fixed_point * ((double)(texture.line_length / 4)
			/ var->p_w_h);
	var->pos = *((unsigned int *)texture.addr + var->y_text
			* (texture.line_length / 4) + var->x_text);
}
