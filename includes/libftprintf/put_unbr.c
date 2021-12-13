/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:59:56 by yanab             #+#    #+#             */
/*   Updated: 2021/11/29 20:03:30 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unbr(unsigned int nbr)
{
	unsigned int	num;

	if (nbr >= 10)
		put_unbr(nbr / 10);
	num = nbr % 10 + '0';
	write(1, &num, 1);
	return (numlen(nbr));
}
