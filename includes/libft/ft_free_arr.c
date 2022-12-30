/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:33:06 by cipher            #+#    #+#             */
/*   Updated: 2022/11/03 05:21:51 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_arr(char ***arr)
{
	int	i;

	i = -1;
	while ((*arr)[++i])
		free((*arr)[i]);
	free(*arr);
	*arr = NULL;
}