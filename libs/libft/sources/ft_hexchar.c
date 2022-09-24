/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:12:06 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 17:45:17 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hexchar(char c)
{
	char			*base;
	unsigned char	hex;

	base = "0123456789abcdef";
	hex = (unsigned char)c;
	ft_putchar('\\');
	ft_putchar(base[hex / 16]);
	ft_putchar(base[hex % 16]);
}
