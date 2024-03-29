/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 09:30:52 by yanab             #+#    #+#             */
/*   Updated: 2022/11/10 18:07:43 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_any(const char *str, int (*f)(char))
{
	while (*str)
	{
		if (f(*str))
			return (1);
		str++;
	}
	return (0);
}
