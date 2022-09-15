/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:02:20 by fbingol           #+#    #+#             */
/*   Updated: 2022/06/29 12:08:29 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
INT_MIN:	   -2147483648
INT_MAX:		2147483647
*/
long	ft_number_length(long n)
{
	long	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	long	n_long;
	long	length;
	char	*value;

	n_long = n;
	length = ft_number_length(n_long);
	value = (char *)malloc(sizeof(char) * (length + 1));
	if (value == NULL)
		return (NULL);
	value[length] = '\0';
	length--;
	if (n_long < 0)
		n_long = -n_long;
	while (length >= 0)
	{
		value[length] = (n_long % 10) + '0';
		length--;
		n_long /= 10;
	}
	if (ft_sign(n) == 1)
		value[0] = '-';
	return (value);
}
