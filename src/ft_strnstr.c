/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:12:27 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/19 19:12:29 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while (needle[i] && haystack[i] == needle[i] && i < len)
		i++;
	if (!needle[i])
		return ((char *)haystack);
	else if (!haystack[i] || !len)
		return (NULL);
	else
		return (ft_strnstr(haystack + 1, needle, len - 1));
}
