/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemaill <ldemaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:54:11 by ldemaill          #+#    #+#             */
/*   Updated: 2025/12/09 16:05:50 by ldemaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_params_c_s_d_i_u(const char str, va_list arg);
static int	ft_params_x_p(const char st, va_list a);
static int	ft_params_adress(va_list arguments);
static int	ft_sort_params(const char s, va_list ar);

int	ft_printf(const char *str, ...)
{
	size_t	i;
	ssize_t	count;
	va_list	arguments;

	va_start(arguments, str);
	count = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_sort_params(str[i], arguments);
			if (count == -1)
				return (-1);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(arguments);
	return (count);
}

static int	ft_sort_params(const char s, va_list ar)
{
	ssize_t	count;
	int		check;

	count = 0;
	if (s == 'c' || s == 's' || s == '%' || s == 'd'
		|| s == 'i' || s == 'u')
	{
		check = ft_params_c_s_d_i_u(s, ar);
		if (check == -1)
			return (-1);
		count = check;
	}
	else if (s == 'X' || s == 'x' || s == 'p')
	{
		check = ft_params_x_p(s, ar);
		if (check == -1)
			return (-1);
		count = check;
	}
	else
	{
		count += ft_putchar_fd('%', 1);
		count += ft_putchar_fd(s, 1);
	}
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
		output = ft_uitoa((uintptr_t)temp, "0123456789abcdef");
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
// 	int				count;
// 	int				y;

// 	s = "%%%%";
// 	u = 548763544;
// 	d = -92233724;
// 	p = &d;
// 	y = d;
// 	ft_printf("******* vrai printf *******\n");
// 	count = printf("s=%s\nu=%u\nd=%d\nmem=%p\n", s, u, d, p);
// 	printf("           %d\n", count);
// 	ft_printf("***************************\n");
// 	ft_printf("\n");
// 	ft_printf("****** mon ft_printf ******\n");
// 	count = ft_printf("s=%s\nu=%u\nd=%d\nmem=%p\n", s, u, d, p);
// 	printf("           %d\n", count);
// 	ft_printf("***************************\n");
// 	return (0);
// }
