/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:17:39 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/09 10:33:19 by mmanouze         ###   ########.fr       */
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
		var->key_a_d = key;
	if (key == K_S || key == K_W)
		var->key_w_s = key;
	if (key == K_AR_L || key == K_AR_R)
		var->key_r_l = key;
	if (key == K_AR_U || key == K_AR_D)
		var->key_u_d = key;
	if (key == K_ESC)
		exit(0);
	return (0);
}

int	reset_keys(int key, t_global *var)
{
	if (key == K_A || key == K_D)
		var->key_a_d = -1;
	if (key == K_S || key == K_W)
		var->key_w_s = -1;
	if (key == K_AR_L || key == K_AR_R)
		var->key_r_l = -1;
	if (key == K_AR_U || key == K_AR_D)
		var->key_u_d = -1;
	return (0);
}

int	key_manager(t_global *var)
{
	if (var->key_a_d == K_A)
		ft_left(var);
	else if (var->key_a_d == K_D)
		ft_right(var);
	if (var->key_w_s == K_S)
		ft_up(var);
	else if (var->key_w_s == K_W)
		ft_down(var);
	if (var->key_r_l == K_AR_L)
		ft_turn_left(var);
	else if (var->key_r_l == K_AR_R)
		ft_turn_right(var);
	if (var->key_u_d == K_AR_U)
		ft_down(var);
	else if (var->key_u_d == K_AR_D)
		ft_up(var);
	return (0);
}
