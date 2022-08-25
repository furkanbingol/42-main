/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:48:32 by fbingol           #+#    #+#             */
/*   Updated: 2022/08/24 15:35:34 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i = (i * 10) + (*str - '0');
		str++;
	}
	return (i);
}

void	ft_bit_and_shift(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("There is a problem, you have to enter 3 arguments.");
		return (0);
	}
	ft_bit_and_shift(ft_atoi(argv[1]), argv[2]);
}
