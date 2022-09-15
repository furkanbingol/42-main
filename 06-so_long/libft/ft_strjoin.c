/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:58:32 by fbingol           #+#    #+#             */
/*   Updated: 2022/09/12 19:44:41 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (ft_strdup(""));
		if (!s1)
			return (ft_strdup(s2));
		return (ft_strdup(s1));
	}
	i = -1;
	j = -1;
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (0);
	while (s1[++i])
		newstr[i] = s1[i];
	while (s2[++j])
		if (s2[j] != 13)
			newstr[i++] = s2[j];
	newstr[i] = '\0';
	return (newstr);
}
