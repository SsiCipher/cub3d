/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 04:15:14 by yanab             #+#    #+#             */
/*   Updated: 2023/01/09 10:30:01 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	degree_to_radian(int degree)
{
	return (degree * (M_PI / 180));
}

int	far_wall_condition(t_global *var, double fov, int speed, double yf)
{
	double	yc;

	yc = sin(fov);
	if (
		var->scene->map[(int)(var->yhitwall) / DIMENSION]
		[(int)(var->xhitwall) / DIMENSION] == '1'
		|| var->scene->map[(int)(var->yhitwall + yc + yf) / DIMENSION]
		[(int)(var->xhitwall - cos(fov) + (cos(fov) * speed)) / DIMENSION]
		== '1'
		|| var->scene->map[(int)(var->yhitwall - yc - yf) / DIMENSION]
		[(int)(var->xhitwall + cos(fov) + (cos(fov) * speed)) / DIMENSION]
		== '1'
		|| var->scene->map[(int)(var->yhitwall - yc + yf) / DIMENSION]
		[(int)(var->xhitwall + cos(fov) - (cos(fov) * speed)) / DIMENSION]
		== '1'
		||var->scene->map[(int)(var->yhitwall + yc - yf) / DIMENSION]
		[(int)(var->xhitwall - cos(fov) - (cos(fov) * speed)) / DIMENSION]
		== '1')
		return (1);
	return (0);
}
