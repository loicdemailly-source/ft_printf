/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemaill <ldemaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:20:21 by ldemaill          #+#    #+#             */
/*   Updated: 2025/12/12 10:46:14 by ldemaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

ssize_t	ft_putstr_nil_fd(char *s, int fd)
{
	if (!s)
		return (write(fd, "(nil)", 5));
	return (write(fd, s, ft_strlen(s)));
}

ssize_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
