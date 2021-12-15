/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:15:40 by yanab             #+#    #+#             */
/*   Updated: 2021/12/15 16:55:29 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Print error and exit
void	print_err(char *err)
{
	ft_printf(err);
	exit(0);
}

// Program main function
int	main(int argc, char const *argv[])
{
	int		map_fd;
	t_data	game_data;

	if (argc != 2)
		print_err("Usage: ./solong <map_file>\n");
	init_data(argv[1], &game_data);
	render_map(&game_data);
	printf("Start");
	mlx_key_hook(game_data.window.element, handle_key_event, &game_data);
	mlx_hook(game_data.window.element, 17, 0, close_window, NULL);
	mlx_loop_hook(game_data.mlx, animate_game, &game_data);
	mlx_loop(game_data.mlx);
	return (0);
}
