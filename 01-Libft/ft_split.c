/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbingol <fbingol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:55:46 by fbingol           #+#    #+#             */
/*   Updated: 2022/06/29 14:50:34 by fbingol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_number_of_words(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	*ft_add_word(char *word, char const *s, int i, int word_length)
{
	int	k;

	k = 0;
	while (word_length > 0)
	{
		word[k] = s[i - word_length];
		k++;
		word_length--;
	}
	word[k] = '\0';
	return (word);
}

char	**ft_split_words(char const *s, char c, char **tab, int num_words)
{
	int	i;
	int	word_no;
	int	word_length;

	i = 0;
	word_no = 0;
	while (word_no < num_words)
	{
		word_length = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_length++;
		}
		tab[word_no] = (char *)malloc(sizeof(char) * (word_length + 1));
		if (tab == NULL)
			return (NULL);
		ft_add_word(tab[word_no], s, i, word_length);
		word_no++;
	}
	tab[word_no] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		num_words;

	if (s == NULL)
		return (NULL);
	num_words = ft_number_of_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (tab == NULL)
		return (NULL);
	ft_split_words(s, c, tab, num_words);
	return (tab);
}
