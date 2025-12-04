/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemaill <ldemaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:05:03 by ldemaill          #+#    #+#             */
/*   Updated: 2025/12/04 11:08:19 by ldemaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	ft_uitoa_len(unsigned long long ln, char *base);

char	*ft_uitoa(unsigned long long n, char *base)
{
	char					*str;
	unsigned long long		i;
	unsigned long long		j;

	j = n;
	i = ft_uitoa_len(n, base);
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

static unsigned long long	ft_uitoa_len(unsigned long long ln, char *base)
{
	unsigned long long	len;
	unsigned long long	i;

	len = 0;
	i = ft_strlen(base);
	if (ln == 0)
		return (1);
	if (ln <= 0)
	{
		len++;
		ln = -ln;
	}
	while (ln > 0)
	{
		ln /= i;
		len++;
	}
	return (len);
}
