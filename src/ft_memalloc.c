/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:09:21 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/19 19:09:22 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*addr;

	if (!(addr = malloc(size)))
		return (NULL);
	while (size > 0)
	{
		size--;
		((unsigned char *)addr)[size] = 0;
	}
	return (addr);
}
