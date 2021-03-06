/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:18:19 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/16 01:18:20 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	compteur;
	int		j;

	compteur = 0;
	while ((*big || *big == *little) && compteur <= len)
	{
		i = 0;
		j = 0;
		while (big[j] == little[i] && little[j] != '\0' && compteur < len)
		{
			compteur++;
			j++;
			i++;
		}
		if (little[i] == '\0')
			return ((char*)big);
		compteur -= j;
		compteur++;
		big++;
	}
	return (NULL);
}
