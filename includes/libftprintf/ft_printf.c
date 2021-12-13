/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:35:35 by yanab             #+#    #+#             */
/*   Updated: 2021/11/26 19:35:35 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_conversion(const char *format, int i, va_list	arg_ptr)
{
	if (format[i] == '%')
		return (put_char('%'));
	else if (format[i] == 'c')
		return (put_char((char)va_arg(arg_ptr, int)));
	else if (format[i] == 's')
		return (put_str((char *)va_arg(arg_ptr, char *)));
	else if (format[i] == 'p')
		return (put_ptr((unsigned long)va_arg(arg_ptr, void *)));
	else if (format[i] == 'd' || format[i] == 'i')
		return (put_nbr(va_arg(arg_ptr, int)));
	else if (format[i] == 'u')
		return (put_unbr(va_arg(arg_ptr, unsigned int)));
	else if (format[i] == 'x' || format[i] == 'X')
		return (put_hex((unsigned int)va_arg(arg_ptr, int), format[i]));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		char_count;
	va_list	arg_ptr;

	i = 0;
	char_count = 0;
	va_start(arg_ptr, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			char_count += put_char(format[i]);
			i++;
		}
		else
		{
			char_count += parse_conversion(format, i + 1, arg_ptr);
			i += 2;
		}
	}
	va_end(arg_ptr);
	return (char_count);
}
