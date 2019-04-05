/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:06:49 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/16 01:06:50 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_index(const char *str, char c)
{
	int index;

	index = 0;
	while (str[index] && str[index] != c)
		index++;
	return (index);
}
