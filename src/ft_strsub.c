/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:12:52 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/19 19:12:55 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*sub;

	while (start--)
		s++;
	if (!(sub = (char *)malloc(len + 1)))
		return (NULL);
	sub[len] = '\0';
	while (len--)
		sub[len] = s[len];
	return (sub);
}
