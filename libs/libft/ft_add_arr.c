/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 04:29:00 by yanab             #+#    #+#             */
/*   Updated: 2022/11/03 03:54:30 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_add_arr(char **arr, size_t index, char *value)
{
	size_t	i;
	size_t	arr_size;
	char	**new_arr;

	arr_size = 0;
	while (arr[arr_size])
		arr_size++;
	new_arr = malloc(sizeof(char *) * (arr_size + 2));
	i = -1;
	while (++i < arr_size + 1)
	{
		if (i < index)
			new_arr[i] = arr[i];
		else if (i == index)
			new_arr[i] = ft_strdup(value);
		else
			new_arr[i] = arr[i - 1];
	}
	new_arr[i] = NULL;
	free(arr);
	return (new_arr);
}
