/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:09:13 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/19 19:09:15 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*cur;

	new = NULL;
	while (lst)
	{
		if (!new)
		{
			if (!(new = f(lst)))
				return (NULL);
			cur = new;
		}
		else
		{
			if (!(cur->next = f(lst)))
				return (NULL);
			cur = cur->next;
		}
		lst = lst->next;
	}
	return (new);
}
