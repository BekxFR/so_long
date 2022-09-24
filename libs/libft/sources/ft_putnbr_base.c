/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:43:41 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 18:10:42 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long int nbr, char *base)
{
	int	i;

	i = ft_basecheck(base);
	if (ft_basecheck(base) > 0 && ft_strdouble(base) == 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		while (i <= nbr)
		{
			ft_putnbr_base(nbr / i, base);
			nbr = nbr % i;
		}
		ft_putchar(base[nbr]);
	}
}
