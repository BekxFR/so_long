/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:02:38 by chillion          #+#    #+#             */
/*   Updated: 2022/10/05 18:13:56 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "libft.h"

# define BUFFER_SIZE 100

char	*get_next_line(int fd);
char	*rest_line(char *str);
char	*keep_line(char *str);
char	*get_read_fd(int fd, char *str);

#endif