/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_nil_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemaill <ldemaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:20:21 by ldemaill          #+#    #+#             */
/*   Updated: 2025/12/09 16:07:34 by ldemaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_nil_fd(char *s, int fd)
{
	if (!s)
		return (write(fd, "(nil)", 5));
	return (write(fd, s, ft_strlen(s)));
}
