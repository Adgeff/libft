/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitmore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:12:39 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/19 19:12:42 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int			ft_issep(char c, const char *sep)
{
	size_t			i;

	i = 0;
	while (sep[i])
		if (sep[i++] == c)
			return (1);
	return (0);
}

static size_t		ft_count_words(const char *s, const char *sep)
{
	size_t			words;

	words = 0;
	while (*s)
	{
		while (ft_issep(*s, sep))
			s++;
		if (*s)
			words++;
		while (*s && !ft_issep(*s, sep))
			s++;
	}
	return (words);
}

static char			*ft_word_dup(const char *s, const char *sep)
{
	char			*word;
	size_t			i;

	i = 0;
	while (s[i] && !ft_issep(s[i], sep))
		i++;
	if (!(word = (char *)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s[i] && !ft_issep(s[i], sep))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char				**ft_strsplitmore(const char *s, const char *sep)
{
	char			**tab;
	unsigned int	words;

	if (!(tab = (char **)malloc((ft_count_words(s, sep) + 1) * sizeof(char *))))
		return (NULL);
	words = 0;
	while (*s)
	{
		while (ft_issep(*s, sep))
			s++;
		if (*s && !(tab[words++] = ft_word_dup(s, sep)))
			return (NULL);
		while (*s && !ft_issep(*s, sep))
			s++;
	}
	tab[words] = NULL;
	return (tab);
}
