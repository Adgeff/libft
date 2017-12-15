/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:07:11 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/19 19:07:14 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_factorial(unsigned int n)
{
	if (n > 12)
		return (0);
	else if (n < 2)
		return (1);
	else
		return (n * ft_factorial(n - 1));
}
