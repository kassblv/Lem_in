/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:14:00 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/16 01:14:01 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_str_reverse(char *str)
{
	int		i;
	int		len;
	char	swap;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len - i)
	{
		swap = str[i];
		str[i] = str[len - i];
		str[len - i] = swap;
		i++;
	}
}
