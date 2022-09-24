/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:10:16 by chillion          #+#    #+#             */
/*   Updated: 2022/09/16 14:40:29 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int			ft_printf(const char *format, ...);
int			ft_format_di(int nbr, char *base, t_l *tl);
int			ft_format_x(unsigned int nbr, char *base, t_l *tl);
int			ft_format_u(unsigned int nbr, char *base, t_l *tl);
int			ft_format_s(char *str, t_l *tl);
int			ft_format_c(char c, t_l *tl);
int			ft_format_p(unsigned long int nbr, char *base, t_l *tl);
const char	*ft_wread(const char *format, t_l *tl);
const char	*ft_format_arg(va_list arg, const char *format, t_l *tl);

#endif