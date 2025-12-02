/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemaill <ldemaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:54:11 by ldemaill          #+#    #+#             */
/*   Updated: 2025/12/02 14:42:26 by ldemaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_params_c_s_d_i_u(const char str, va_list arg);
static int	ft_params_x_p(const char st, va_list a);
static int	ft_params_adress(va_list arguments);

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	count;
	va_list	arguments;

	va_start(arguments, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c' || str[i] == 's' || str[i] == '%' || str[i] == 'd'
				|| str[i] == 'i' || str[i] == 'u')
				count += ft_params_c_s_d_i_u(str[i], arguments);
			if (str[i] == 'X' || str[i] == 'x' || str[i] == 'p')
				count += ft_params_x_p(str[i], arguments);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(arguments);
	return (count);
}

static int	ft_params_c_s_d_i_u(const char str, va_list arg)
{
	char	*output;
	size_t	count;

	output = NULL;
	count = 0;
	if (str == 's')
		count = ft_putstr_fd(va_arg(arg, char *), 1);
	if (str == 'c')
		count = ft_putchar_fd(va_arg(arg, int), 1);
	if (str == '%')
		count = ft_putchar_fd('%', 1);
	if (str == 'd' || str == 'i')
	{
		output = ft_itoa(va_arg(arg, int), "0123456789");
		count = ft_putstr_nil_fd(output, 1);
	}
	if (str == 'u')
	{
		output = ft_itoa(va_arg(arg, unsigned int), "0123456789");
		count = ft_putstr_nil_fd(output, 1);
	}
	if (output != NULL)
		free(output);
	return (count);
}

static int	ft_params_x_p(const char st, va_list a)
{
	size_t	count;
	char	*output;

	count = 0;
	if (st == 'X')
	{
		output = ft_itoa(va_arg(a, unsigned int), "0123456789ABCDEF");
		count = ft_putstr_nil_fd(output, 1);
		free(output);
	}
	if (st == 'x')
	{
		output = ft_itoa(va_arg(a, unsigned int), "0123456789abcdef");
		count = ft_putstr_nil_fd(output, 1);
		free(output);
	}
	if (st == 'p')
		count = ft_params_adress(a);
	return (count);
}

static int	ft_params_adress(va_list arguments)
{
	size_t	count;
	char	*output;
	char	*temp;

	count = 0;
	temp = va_arg(arguments, char *);
	if (!temp)
		count += ft_putstr_nil_fd(temp, 1);
	else
	{
		output = ft_itoa((unsigned long)temp, "0123456789abcdef");
		count = ft_putstr_nil_fd("0x", 1);
		count += ft_putstr_nil_fd(output, 1);
		free(output);
	}
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char		*s;
// 	unsigned int	u;
// 	int				d;
// 	void			*p;

// 	s = "%%%%";
// 	u = 564865123;
// 	d = -92233724;
// 	p = &d;
// 	ft_printf("****** mon ft_printf ******\n");
// 	ft_printf("c=%d\n", ft_printf("s=%s\nn=%d\nun=%u\nm=%p\n", s, d, u, p));
// 	ft_printf("***************************\n");
// 	ft_printf("\n");
// 	ft_printf("******* vrai printf *******\n");
// 	ft_printf("c=%d\n", printf("s=%s\nn=%d\nun=%u\nm=%p\n", s, d, u, p));
// 	ft_printf("***************************\n");
// 	return (0);
// }
