/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_dixu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:27:35 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 17:45:30 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_di(int nbr, char *base, t_l *tl)
{
	ft_putnbr_base(nbr, base);
	tl->len = tl->len + ft_nb_size(nbr, base);
	return (tl->len);
}

int	ft_format_x(unsigned int nbr, char *base, t_l *tl)
{
	ft_puthex_base(nbr, base);
	tl->len = tl->len + ft_hex_size(nbr, base);
	return (tl->len);
}

int	ft_format_u(unsigned int nbr, char *base, t_l *tl)
{
	ft_putnbr_base(nbr, base);
	tl->len = tl->len + ft_hex_size(nbr, base);
	return (tl->len);
}
