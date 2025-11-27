/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemaill <ldemaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:54:11 by ldemaill          #+#    #+#             */
/*   Updated: 2025/11/27 11:49:17 by ldemaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list arguments;
	va_start(arguments, str);
	
	
	i = 0;
	while (str[i])
	{
		ft_print(str, '%', i);
		if (str[++i] == 37)
			ft_params(str);
		i++;
	}
	
}

void	ft_putnbr(int n)
{
	char	valnb;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = (n * -1);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		valnb = n + '0';
		write(1, &valnb, 1);
	}
}

void	ft_params(char *str)
{
	int i;
			if (str[i] == 'c' || str[i] == 's')
				ft_putstr();
			if (str[i] == 'p')
				ft_hexvoidptr();
			if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr(5);
			if (str[i] == 'u')
				ft_printunsigneddecimal();
			if (str[i] == 'X' || str[i] == 'x')
				ft_putstr(ft_toupper(ft_hex()));
				ft_putstr(ft_tolower(ft_hex()));
			if (str[i] == '%')
				write(1, 37, 1);
}

void	ft_print(char *s, char sep, int index)
{
	while (s[index] != sep)
		index++;
	write(1, s, index);
	return (0);
}

