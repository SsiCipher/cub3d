/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:00:08 by yanab             #+#    #+#             */
/*   Updated: 2021/11/29 20:45:10 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex(unsigned int n, char c_case)
{
	int		i;
	int		total;
	char	*base;
	char	result[16];

	if (c_case == 'x')
		base = "0123456789abcdef";
	else if (c_case == 'X')
		base = "0123456789ABCDEF";
	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		result[i++] = base[n % 16];
		n /= 16;
	}
	total = 0;
	while (--i >= 0)
		total += write(1, &result[i], 1);
	return (total);
}
