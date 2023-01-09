/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:17:39 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/09 05:21:08 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop_event(t_global *var)
{
	key_manager(var);
	player_view(var);
	mlx_put_image_to_window(&var, var->mlx_win, var->mlx_img.content, 0, 0);
	return (0);
}

int	init_keys(int key, t_global *var)
{
	if (key == K_A || key == K_D)
		var->key_A_D = key;
	if (key == K_S || key == K_W)
		var->key_W_S = key;
	if (key == K_AR_L || key == K_AR_R)
		var->key_R_L = key;
	if (key == K_AR_U || key == K_AR_D)
		var->key_U_D = key;
	if (key == K_ESC)
		exit(0);
	return (0);
}

int	reset_keys(int key, t_global *var)
{
	if (key == K_A || key == K_D)
		var->key_A_D = -1;
	if (key == K_S || key == K_W)
		var->key_W_S = -1;
	if (key == K_AR_L || key == K_AR_R)
		var->key_R_L = -1;
	if (key == K_AR_U || key == K_AR_D)
		var->key_U_D = -1;
	return (0);
}

int	key_manager(t_global *var)
{
	if (var->key_A_D == K_A)
		ft_left(var);
	else if (var->key_A_D == K_D)
		ft_right(var);
	if (var->key_W_S == K_S)
		ft_up(var);
	else if (var->key_W_S == K_W)
		ft_down(var);
	if (var->key_R_L == K_AR_L)
		ft_turn_left(var);
	else if (var->key_R_L == K_AR_R)
		ft_turn_right(var);
	if (var->key_U_D == K_AR_U)
		ft_down(var);
	else if (var->key_U_D == K_AR_D)
		ft_up(var);
	return (0);
}
