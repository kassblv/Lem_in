/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnoctet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:13:23 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/16 01:13:24 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnoctet(void *str, size_t n)
{
	unsigned char *cstr;

	cstr = (unsigned char *)str;
	while (n > 0)
	{
		ft_putchar(*cstr);
		cstr++;
		n--;
	}
}
