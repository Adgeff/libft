/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:10:42 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/19 19:22:07 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			ft_power(int nb, unsigned int power)
{
	if (!power)
		return (1);
	else
		return (nb * ft_power(nb, power - 1));
}

unsigned int		ft_root(unsigned int nb, unsigned int root)
{
	unsigned int	i;

	if (!root || !nb)
		return (0);
	i = 1;
	while (i < nb / ft_power(i, root - 1))
		i++;
	if (nb == (unsigned)ft_power(i, root))
		return (i);
	else
		return (0);
}
