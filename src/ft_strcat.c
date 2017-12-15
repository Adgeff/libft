/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:10:46 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/19 19:10:48 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	char	*cpy;

	cpy = s1;
	while (*cpy)
		cpy++;
	i = 0;
	while (s2[i])
	{
		cpy[i] = s2[i];
		i++;
	}
	cpy[i] = '\0';
	return (s1);
}
