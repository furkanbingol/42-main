/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:54:27 by fbingol           #+#    #+#             */
/*   Updated: 2022/09/12 19:33:09 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*(unsigned char *)s != (unsigned char)c)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (ft_strlen(s) < start)
		return (0);
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (0);
	i = 0;
	while (s[i] && i < len)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = 0;
	return (substr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_strjoin(const char *s1, const char *s2)
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
