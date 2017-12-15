/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:12:34 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/19 19:12:38 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t		ft_count_words(const char *s, char c)
{
	size_t			words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

static char			*ft_word_dup(const char *s, char c)
{
	char			*word;
	size_t			i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(word = (char *)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char				**ft_strsplit(const char *s, char c)
{
	char			**tab;
	unsigned int	words;

	if (!(tab = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *))))
		return (NULL);
	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && !(tab[words++] = ft_word_dup(s, c)))
			return (NULL);
		while (*s && *s != c)
			s++;
	}
	tab[words] = NULL;
	return (tab);
}
