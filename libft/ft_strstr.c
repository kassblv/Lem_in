/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:19:10 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/16 01:19:12 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strstr(const char *str, const char *little)
{
	int i;
	int x;

	if (little[0] == '\0')
		return ((char *)str);
	i = 0;
	while (str[i])
	{
		x = 0;
		while (little[x] == str[i + x])
		{
			if (!little[x + 1])
				return ((char *)(str + i));
			x++;
		}
		i++;
	}
	return (NULL);
}
