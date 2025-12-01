/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemaill <ldemaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:06:32 by ldemaill          #+#    #+#             */
/*   Updated: 2025/12/01 15:22:17 by ldemaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	ft_itoa_len(long long int itoalen, char *base);

char	*ft_itoa(long long int n, char *base)
{
	char				*str;
	long long int		i;
	long long int		j;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	j = n;
	i = ft_itoa_len(n, base);
	str = ft_calloc((i + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (j == 0)
		str[0] = '0';
	if (j < 0)
	{
		str[0] = '-';
		j = -j;
	}
	while (j > 0)
	{
		str[--i] = base[j % ft_strlen(base)];
		j /= ft_strlen(base);
	}
	return (str);
}

static long long int	ft_itoa_len(long long int itoalen, char *base)
{
	long long int	len;
	long long int	i;

	len = 0;
	i = ft_strlen(base);
	if (itoalen == 0)
		return (1);
	if (itoalen <= 0)
	{
		len++;
		itoalen = -itoalen;
	}
	while (itoalen > 0)
	{
		itoalen /= i;
		len++;
	}
	return (len);
}
