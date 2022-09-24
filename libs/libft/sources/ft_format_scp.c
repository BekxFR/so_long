/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_scp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:27:19 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 17:45:36 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_s(char *str, t_l *tl)
{
	if (!str)
	{
		write(1, "(null)", 6);
		tl->len = tl->len + 6;
		return (tl->len);
	}
	else
	{
		ft_putstr(str);
		tl->len = tl->len + ft_strlen(str);
		return (tl->len);
	}
}

int	ft_format_c(char c, t_l *tl)
{
	if (c == '%')
	{
		ft_putchar('%');
		tl->len = tl->len + 1;
		return (tl->len);
	}
	else
	{
		ft_putchar(c);
		tl->len = tl->len + 1;
		return (tl->len);
	}
}

int	ft_format_p(unsigned long int nbr, char *base, t_l *tl)
{
	if (!nbr)
	{
		write(1, "(nil)", 5);
		tl->len = tl->len + 5;
		return (tl->len);
	}
	else
	{
		write(1, "0x", 2);
		ft_puthex_base(nbr, base);
		tl->len = tl->len + 2 + ft_hex_size(nbr, base);
		return (tl->len);
	}
}
