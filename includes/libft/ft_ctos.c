/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:28:55 by cipher            #+#    #+#             */
/*   Updated: 2022/11/05 02:34:40 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ctos(char chr, int count)
{
	char	*output;

	output = (char *)malloc(sizeof(char) * (count + 1));
	ft_memset(output, chr, count);
	output[count] = '\0';
	return (output);
}
