/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:58:32 by fbingol           #+#    #+#             */
/*   Updated: 2022/10/17 11:57:42 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*r_str;
	size_t	i;
	size_t	j;

	r_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	i = -1;
	j = -1;
	while (s1[++i])
		r_str[i] = s1[i];
	r_str[i] = ' ';
	i++;
	while (s2[++j])
		r_str[i++] = s2[j];
	r_str[i] = '\0';
	return (r_str);
}
