/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:59:31 by yanab             #+#    #+#             */
/*   Updated: 2021/11/29 20:33:44 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_nbr(int nbr)
{
	int	num;

	if (nbr < 0)
	{
		if (nbr == -2147483648)
			return (write(1, "-2147483648", 11));
		else
		{
			write(1, "-", 1);
			put_nbr(-nbr);
		}
	}
	else
	{
		if (nbr >= 10)
			put_nbr(nbr / 10);
		num = nbr % 10 + '0';
		write(1, &num, 1);
	}
	if (nbr < 0)
		return (1 + numlen(-nbr));
	return (numlen(nbr));
}
