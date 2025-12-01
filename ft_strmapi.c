/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemaill <ldemaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:55:02 by ldemaill          #+#    #+#             */
/*   Updated: 2025/12/01 11:46:00 by ldemaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	i = -1;
	if (s == (void *)0)
		return (NULL);
	if (*f == (void *)0)
		dest = ft_strdup(s);
	dest = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!dest)
		return (NULL);
	while (s[++i])
		dest[i] = f(i, s[i]);
	return (dest);
}
