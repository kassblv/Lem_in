/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:38:59 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/12 09:09:40 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	testneg(int nb)
{
	if (nb < 0)
		nb = nb * -1;
	return (nb);
}

char		*ft_itoa(int nbr)
{
	int len;
	int tmp;
	char*tab;

	len = nbr <= 0;
	tmp = nbr;
	while (tmp != 0)
	{
		tmp /= 10;
		len++;
	}
	if (!(tab = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (nbr == 0)
		tab[0] = '0';
	else if (nbr < 0)
		tab[0] = '-';
	tab[len] = 0;
	while (nbr != 0)
	{
		tab[--len] = '0' + testneg(nbr % 10);
		nbr /= 10;
	}
	return (tab);
}
