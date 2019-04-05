/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:11:04 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/16 01:11:05 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_power(long long number, int power)
{
	long long	result;

	if (power == 0)
		return (1);
	if (power == 1)
		return (number);
	result = number;
	while (power-- && result * number <= __LONG_LONG_MAX__)
		result *= number;
	return (result);
}
