/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:10:05 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/16 01:10:06 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)s;
	while (n > 0)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
