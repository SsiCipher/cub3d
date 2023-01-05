/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:36:29 by yanab             #+#    #+#             */
/*   Updated: 2023/01/05 16:53:19 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_print_scene(t_scene *scene)
{
	printf("north_texture: [%s]\n", scene->north_texture);
	printf("south_texture: [%s]\n", scene->south_texture);
	printf("west_texture: [%s]\n", scene->west_texture);
	printf("east_texture: [%s]\n", scene->east_texture);
	printf("floor_color: [%d]\n", scene->floor_color);
	printf("ceilling_color: [%d]\n", scene->ceilling_color);
	printf("map => width: [%ld], height: [%ld]\n", scene->map_width, scene->map_height);
	for (int i = 0; scene->map[i]; i++)
		printf("%s\n", scene->map[i]);
}
