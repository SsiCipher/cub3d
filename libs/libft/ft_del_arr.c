/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 04:57:18 by yanab             #+#    #+#             */
/*   Updated: 2022/11/03 03:56:59 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_del_arr(char **arr, size_t index)
{
	size_t	i;
	size_t	arr_size;
	char	**new_arr;

	arr_size = 0;
	while (arr[arr_size])
		arr_size++;
	new_arr = malloc(sizeof(char *) * arr_size);
	i = 0;
	while (i < arr_size)
	{
		if (i < index)
			new_arr[i] = arr[i];
		else if (i == index)
			free(arr[i]);
		else
			new_arr[i - 1] = arr[i];
		i++;
	}
	new_arr[i - 1] = NULL;
	free(arr);
	return (new_arr);
}
