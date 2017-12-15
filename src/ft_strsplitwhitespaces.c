/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitwhitespaces.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:12:43 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/19 19:12:45 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t		ft_count_words(const char *s)
{
	size_t			words;

	words = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\t' || *s == '\n')
			s++;
		if (*s)
			words++;
		while (*s && *s != ' ' && *s != '\t' && *s != '\n')
			s++;
	}
	return (words);
}

static char			*ft_word_dup(const char *s)
{
	char			*word;
	size_t			i;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		i++;
	if (!(word = (char *)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char				**ft_strsplitwhitespaces(const char *s)
{
	char			**tab;
	unsigned int	words;

	if (!(tab = (char **)malloc((ft_count_words(s) + 1) * sizeof(char *))))
		return (NULL);
	words = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\t' || *s == '\n')
			s++;
		if (*s && !(tab[words++] = ft_word_dup(s)))
			return (NULL);
		while (*s && *s != ' ' && *s != '\t' && *s != '\n')
			s++;
	}
	tab[words] = NULL;
	return (tab);
}
