/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:03:04 by cipher            #+#    #+#             */
/*   Updated: 2022/11/10 18:05:12 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_str(char *str, int index, char *value)
{
	char	*output;
	char	tmp;

	tmp = str[index];
	str[index] = '\0';
	output = ft_multijoin(3, str, value, &str[index + 1]);
	str[index] = tmp;
	free(str);
	return (output);
}
