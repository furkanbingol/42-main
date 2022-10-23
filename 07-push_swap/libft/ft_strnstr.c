/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 13:54:16 by fbingol           #+#    #+#             */
/*   Updated: 2022/06/29 15:43:14 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strnstr() function locates the first occurrence of 
the null-terminated string needle in the string haystack, where not 
more than len characters are searched.

If needle is an empty string, haystack is returned.
If needle occurs nowhere in haystack, NULL is returned.
Otherwise a pointer to the first character of the first occurrence of 
needle is returned.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	if (needle[0] == '\0')
		return ((char *)haystack);
	h = 0;
	while (haystack[h])
	{
		n = 0;
		while (haystack[h + n] == needle[n] && (h + n) < len)
		{
			if (haystack[h + n] == '\0' && needle[n] == '\0')
				return ((char *)&haystack[h]);
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)&haystack[h]);
		h++;
	}
	return (NULL);
}
