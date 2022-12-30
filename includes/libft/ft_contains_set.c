/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:12:43 by yanab             #+#    #+#             */
/*   Updated: 2022/11/06 13:13:57 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_contains_set(char *str, char *set)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_contains(set, str[i]))
			return (true);
	return (false);
}
