/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemaill <ldemaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 07:44:06 by ldemaill          #+#    #+#             */
/*   Updated: 2025/12/10 17:08:28 by ldemaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	size_t	i;

	i = (nmemb * size);
	if (nmemb != 0 || size != 0)
	{
		if (i / nmemb != size)
			return (0);
	}
	dest = 0;
	dest = malloc(i);
	if (!dest)
		return (NULL);
	ft_bzero(dest, i);
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n && n != 0)
	{
		str[i] = '\0';
		i++;
	}
}
