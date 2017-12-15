/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:08:32 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/19 19:08:35 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		power;

	power = 1;
	i = (n < 0) ? 2 : 1;
	while (n / power >= 10 || n / power <= -10)
	{
		power *= 10;
		i++;
	}
	if (!(result = (char *)malloc(i + 1)))
		return (NULL);
	if (n < 0)
		result[0] = '-';
	i = (n < 0) ? 1 : 0;
	while (power != 0)
	{
		result[i] = n / power % 10 * ((n < 0) ? -1 : 1) + '0';
		power /= 10;
		i++;
	}
	result[i] = '\0';
	return (result);
}
