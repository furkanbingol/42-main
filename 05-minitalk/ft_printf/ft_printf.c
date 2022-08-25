/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:13:05 by fbingol           #+#    #+#             */
/*   Updated: 2022/08/24 14:13:08 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_variable(va_list list, const char a)
{
	int	c;

	c = 0;
	if (a == 'c')
		c += ft_put_char(va_arg(list, int));
	else if (a == 's')
		c += ft_put_string(va_arg(list, char *));
	else if (a == 'p')
		c += ft_hex(va_arg(list, unsigned long), "0123456789abcdef", 1, 16);
	else if (a == 'd' || a == 'i')
		c += ft_putnbr(va_arg(list, int));
	else if (a == 'u')
		c += ft_put_unumber(va_arg(list, unsigned int));
	else if (a == 'x')
		c += ft_hex(va_arg(list, unsigned), "0123456789abcdef", 0, 16);
	else if (a == 'X')
		c += ft_hex(va_arg(list, unsigned), "0123456789ABCDEF", 0, 16);
	else if (a == '%')
		c += write(1, "%", 1);
	return (c);
}

int	ft_printf(const char *str, ...)
{
	int		print_count;
	va_list	list;
	int		c;

	c = 0;
	print_count = 0;
	va_start(list, str);
	while (str[c])
	{
		if (str[c] == '%')
		{
			print_count += ft_variable(list, str[c + 1]);
				c++;
		}
		else
			print_count += ft_put_char(str[c]);
		c++;
	}
	va_end(list);
	return (print_count);
}
