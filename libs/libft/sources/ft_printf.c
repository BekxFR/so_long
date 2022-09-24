/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:27:57 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 17:43:29 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_format_arg(va_list arg, const char *format, t_l *tl)
{
	if (*format == 'd' || *format == 'i')
		tl->len = (ft_format_di(va_arg(arg, int), "0123456789", tl));
	else if (*format == 'u')
		tl->len = (ft_format_u(va_arg(arg, unsigned int), "0123456789", tl));
	else if (*format == 's')
		tl->len = (ft_format_s(va_arg(arg, char *), tl));
	else if (*format == 'x')
		tl->len = (ft_format_x(va_arg(arg, unsigned int),
					"0123456789abcdef", tl));
	else if (*format == 'X')
		tl->len = (ft_format_x(va_arg(arg, unsigned int),
					"0123456789ABCDEF", tl));
	else if (*format == 'c')
		tl->len = (ft_format_c(va_arg(arg, int), tl));
	else if (*format == '%')
		tl->len = (ft_format_c('%', tl));
	else if (*format == 'p')
		tl->len = (ft_format_p(va_arg(arg, unsigned long int),
					"0123456789abcdef", tl));
	else
		return (NULL);
	format++;
	return (format);
}

const char	*ft_wread(const char *format, t_l *tl)
{
	char	*next;

	next = ft_strchr(format, '%');
	if (next)
		tl->str = next - format;
	else
		tl->str = ft_strlen(format);
	write(1, format, tl->str);
	tl->len = tl->len + tl->str;
	while (*format && *format != '%')
		format++;
	return (format);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	t_l		tl;

	tl.len = 0;
	tl.str = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
			format = ft_format_arg(arg, format + 1, &tl);
		else
			format = ft_wread(format, &tl);
		if (!format)
		{
			write(1, "(null)", 6);
			va_end(arg);
			return (tl.len);
		}
	}
	va_end(arg);
	return (tl.len);
}
