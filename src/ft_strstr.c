/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:12:47 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/19 19:12:50 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	if (needle && !(*needle))
		return ((char *)haystack);
	if (!(*haystack))
		return (NULL);
	i = 0;
	while (needle[i] && haystack[i] == needle[i])
		i++;
	if (needle[i])
		return (ft_strstr(haystack + 1, needle));
	return ((char *)haystack);
}
