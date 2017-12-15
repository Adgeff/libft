/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:49:46 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/28 14:45:12 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpushback(t_list **begin_list, t_list *new)
{
	t_list	*list;

	if (*begin_list)
	{
		list = *begin_list;
		while (list && list->next)
			list = list->next;
		list->next = new;
	}
	else
		*begin_list = new;
}
