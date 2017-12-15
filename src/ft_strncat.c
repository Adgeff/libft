/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:12:00 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/19 19:12:04 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*cpy;

	cpy = s1;
	while (*cpy)
		cpy++;
	i = 0;
	while (s2[i] && i < n)
	{
		cpy[i] = s2[i];
		i++;
	}
	cpy[i] = '\0';
	return (s1);
}
