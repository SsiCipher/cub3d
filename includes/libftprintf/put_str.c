/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:59:13 by yanab             #+#    #+#             */
/*   Updated: 2021/11/29 20:26:06 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(char *str)
{
	int	total;

	total = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
		total += write(1, str++, 1);
	return (total);
}
