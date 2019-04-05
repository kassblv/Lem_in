/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:17:30 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/16 01:17:30 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	char	*csrc;

	i = ft_strlen(dest);
	csrc = (char *)src;
	while (n-- && *csrc)
	{
		dest[i] = *csrc;
		csrc++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
