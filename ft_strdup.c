/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemaill <ldemaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:35:04 by ldemaill          #+#    #+#             */
/*   Updated: 2025/12/01 11:49:44 by ldemaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	size_t		i;
	char		*dest;

	dest = 0;
	i = 0;
	dest = ft_calloc((ft_strlen(s) + 1), sizeof(const char));
	if (!dest)
		return (NULL);
	while (i < ft_strlen(s))
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}
