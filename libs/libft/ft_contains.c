/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipher <cipher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:27:42 by cipher            #+#    #+#             */
/*   Updated: 2022/11/05 19:29:25 by cipher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_contains(char *str, char chr)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == chr)
			return (true);
	return (false);
}
