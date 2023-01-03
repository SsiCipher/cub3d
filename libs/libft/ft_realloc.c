/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:18:35 by yanab             #+#    #+#             */
/*   Updated: 2022/03/09 02:46:29 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_buff;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	new_buff = malloc(new_size);
	if (!new_buff)
		return (NULL);
	if (ptr != NULL)
	{
		ft_memcpy(new_buff, ptr, old_size);
		free(ptr);
	}
	return (new_buff);
}
