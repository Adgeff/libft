/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:09:17 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/19 19:09:19 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*new;
	size_t	i;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(new->content = malloc(content_size)))
			return (NULL);
		i = 0;
		while (i < content_size)
		{
			((unsigned char *)new->content)[i] = ((unsigned char *)content)[i];
			i++;
		}
	}
	else
		new->content = NULL;
	new->content_size = (content) ? content_size : 0;
	new->next = NULL;
	return (new);
}
