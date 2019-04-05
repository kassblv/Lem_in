/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:05:47 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/22 11:10:28 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int n;
	int nb;

	n = 1;
	nb = 0;
	if (!nptr || *nptr == '\200')
		return (0);
	while ((*nptr <= ' ' || *nptr == 127) && *nptr != '\e')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			n = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
	{
		nb = nb * 10 + *nptr - 48;
		nptr++;
	}
	return (nb * n);
}
