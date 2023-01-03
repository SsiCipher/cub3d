/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 08:33:05 by cipher            #+#    #+#             */
/*   Updated: 2022/04/12 02:53:24 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_sort_part(int *array, int size, int (*cmp)(int, int))
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++j < size)
	{
		if (cmp(array[j], array[size - 1]) <= 0)
			ft_swap(array, i++, j);
	}
	if (i == 0)
		return (0);
	return (i - 1);
}

int	cmp_func(int a, int b)
{
	return (a - b);
}

void	ft_qsort(int *array, int size, int (*cmp)(int, int))
{
	int	pivot_i;

	if (!cmp)
		cmp = cmp_func;
	if (size > 1)
	{
		pivot_i = ft_sort_part(array, size, cmp);
		ft_qsort(array, pivot_i, cmp);
		ft_qsort(array + pivot_i + 1, size - (pivot_i + 1), cmp);
	}
}
