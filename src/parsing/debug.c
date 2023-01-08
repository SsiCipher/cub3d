/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:36:29 by yanab             #+#    #+#             */
/*   Updated: 2023/01/08 04:30:15 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_print_scene(t_scene *scene)
{
	printf("Player is in x:%f y:%f\n", scene->player.x, scene->player.y);
	printf("Floor color: %d, ceilling color: %d\n", scene->floor_color, scene->ceilling_color);
	printf("map => width: [%ld], height: [%ld]\n", scene->map_width, scene->map_height);
	for (int i = 0; scene->map[i]; i++)
		printf("%s\n", scene->map[i]);
}
