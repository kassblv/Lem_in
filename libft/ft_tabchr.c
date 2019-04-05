/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <kaboujna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 13:01:06 by kaboujna          #+#    #+#             */
/*   Updated: 2019/01/05 13:14:11 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_tabchr(char **tab, char *str)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (ft_strequ(tab[i], str))
			return ((char *)tab[i]);
		i++;
	}
	return (NULL);
}
