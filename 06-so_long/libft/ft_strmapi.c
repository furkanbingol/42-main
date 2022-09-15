/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:21:41 by fbingol           #+#    #+#             */
/*   Updated: 2022/06/29 18:20:52 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	int		i;

	if (s == NULL)
		return ((char *)s);
	i = 0;
	string = ft_strdup(s);
	if (string == NULL)
		return (NULL);
	while (string[i])
	{
		string[i] = f(i, string[i]);
		i++;
	}
	return (string);
}
