/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:25:38 by fbingol           #+#    #+#             */
/*   Updated: 2022/06/29 14:39:19 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
fd(file descriptor) values;
0:	Standard input	
1:	Standard output
2:	Standard error

int fd = open(file_path, mod); 
(mod: O_RDONLY | O_CREAT...)

Range of possible values of "fd" is from 0 to 1023 for Linux system.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
