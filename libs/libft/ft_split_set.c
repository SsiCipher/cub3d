/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipher <cipher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:13:23 by yanab             #+#    #+#             */
/*   Updated: 2022/11/05 19:46:02 by cipher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_parts(char const *str, char *set)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	if (*str == '\0')
		return (0);
	while (ft_strchr(set, str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (ft_strchr(set, str[i]) && !ft_strchr(set, str[i + 1]) && str[i + 1])
			count++;
		i++;
	}
	return (count);
}

static char	*ft_nth_part(char const *str, char *set, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	if (*str == '\0')
		return (&((char *)str)[0]);
	while (ft_strchr(set, str[i]))
		i++;
	if (str[i] == '\0')
		return (&((char *)str)[0]);
	while (str[i])
	{
		if (count == n)
			return (&((char *)str)[i]);
		if (ft_strchr(set, str[i]) && !ft_strchr(set, str[i + 1]) && str[i + 1])
			count++;
		i++;
	}
	return (NULL);
}

static int	ft_partlen(char *part_start, char *set)
{
	int	len;

	len = 0;
	while (part_start[len] && !ft_strchr(set, part_start[len]))
		len++;
	return (len);
}

static void	free_split(char **split_str, int i)
{
	while (i--)
		free(split_str[i]);
	free(split_str);
}

char	**ft_split_set(char const *s, char *set)
{
	int		i;
	char	*part_start;
	int		parts_count;
	char	**split_str;

	if (s == NULL)
		return (NULL);
	parts_count = ft_count_parts(s, set);
	split_str = (char **)malloc(sizeof(char *) * (parts_count + 1));
	if (!split_str)
		return (NULL);
	i = -1;
	while (++i < parts_count)
	{
		part_start = ft_nth_part(s, set, i + 1);
		split_str[i] = ft_substr(part_start, 0, ft_partlen(part_start, set));
		if (!split_str[i])
		{
			free_split(split_str, i);
			return (NULL);
		}
	}
	split_str[i] = NULL;
	return (split_str);
}
