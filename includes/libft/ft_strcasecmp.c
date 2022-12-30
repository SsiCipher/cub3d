/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 06:10:32 by yanab             #+#    #+#             */
/*   Updated: 2022/11/10 18:25:11 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcasecmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (ft_toupper(s1[i]) != ft_toupper(s2[i]))
			break ;
		i++;
	}
	return ((unsigned char)ft_toupper(s1[i]) -(unsigned char)ft_toupper(s2[i]));
}
