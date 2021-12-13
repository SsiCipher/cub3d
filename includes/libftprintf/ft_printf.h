/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:18:49 by yanab             #+#    #+#             */
/*   Updated: 2021/11/29 16:18:49 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);

int	put_char(char c);
int	put_str(char *str);
int	numlen(unsigned int nbr);
int	put_nbr(int nbr);
int	put_unbr(unsigned int nbr);
int	put_hex(unsigned int n, char c_case);
int	put_ptr(unsigned long n);

#endif
