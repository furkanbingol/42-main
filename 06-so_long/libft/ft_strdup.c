/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:34:20 by fbingol           #+#    #+#             */
/*   Updated: 2022/09/12 19:15:03 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
-The strdup() function allocates sufficient memory for a copy of the string 
 s1, does the copy, and returns a pointer to it.
*/
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		n;
	int		l;

	l = ft_strlen(s1);
	n = 0;
	ptr = malloc(sizeof(char) * l + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[n])
	{
		if (s1[n] != 13)
			ptr[n] = s1[n];
		else
		{
			ptr[n] = '\n';
			ptr[n + 1] = '\0';
			return (ptr);
		}
		n++;
	}
	ptr[n] = '\0';
	return (ptr);
}
