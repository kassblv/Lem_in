/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:16:50 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/16 01:16:50 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t len1;
	size_t len2;

	i = 0;
	len1 = ft_strlen(dest);
	len2 = ft_strlen((char *)src);
	if (size <= len1)
		return (len2 + size);
	while (i < size - len1 - 1 && src[i])
	{
		dest[len1 + i] = src[i];
		i++;
	}
	dest[len1 + i] = '\0';
	return (len1 + len2);
}
