/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 22:16:40 by marvin            #+#    #+#             */
/*   Updated: 2022/11/10 18:26:17 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbin_fd(unsigned int n, int fd, bool is_prefixed)
{
	char	*base;

	base = "01";
	if (is_prefixed)
		ft_putstr_fd("0b", fd);
	if (n >= 2)
		ft_putbin_fd(n / 2, fd, false);
	ft_putchar_fd(base[n % 2], fd);
}
