/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:54:49 by fbingol           #+#    #+#             */
/*   Updated: 2022/07/04 12:36:13 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# ifndef LOWER_BASE
#  define LOWER_BASE "0123456789abcdef"
# endif

# ifndef UPPER_BASE
#  define UPPER_BASE "0123456789ABCDEF"
# endif

int	ft_printf(const char *str, ...);
int	ft_control(char ch, va_list va);
int	put_char(int c);
int	put_str(char *str);
int	put_nbr(long double nbr, int base, int is_upper);
int	put_point(long double nbr, int base, int is_upper);

#endif