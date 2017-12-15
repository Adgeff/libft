/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:12:56 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/19 19:12:58 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strtrim(const char *s)
{
	char	*trim;
	int		len;

	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	len = 0;
	while (s[len])
		len++;
	len--;
	while (len > 0 && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	len++;
	if (!(trim = (char *)malloc(len + 1)))
		return (NULL);
	trim[len] = '\0';
	while (len--)
		trim[len] = s[len];
	return (trim);
}
