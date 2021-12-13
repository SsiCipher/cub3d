/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:00:25 by yanab             #+#    #+#             */
/*   Updated: 2021/11/29 20:41:36 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_ptr(unsigned long n)
{
	int		i;
	int		total;
	char	*base;
	char	result[16];

	i = 0;
	base = "0123456789abcdef";
	if (n == 0)
		return (write(1, "0x0", 3));
	while (n > 0)
	{
		result[i++] = base[n % 16];
		n /= 16;
	}
	total = put_str("0x");
	while (--i >= 0)
		total += write(1, &result[i], 1);
	return (total);
}
