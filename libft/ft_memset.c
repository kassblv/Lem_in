/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:10:56 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/16 01:10:57 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)s;
	while (n > 0)
	{
		*tmp = (unsigned char)c;
		tmp++;
		n--;
	}
	return (s);
}
