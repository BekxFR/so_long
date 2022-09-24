/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:53:46 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 17:43:11 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		*base;
	long int	nb;

	base = "0123456789";
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	while (10 <= nb)
	{
		ft_putnbr_fd((nb / 10), fd);
		nb = nb % 10;
	}
	ft_putchar_fd(base[nb], fd);
}
