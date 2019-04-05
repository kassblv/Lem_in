/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:14:59 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/16 01:14:59 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcreate(size_t size, char c)
{
	char	*array;

	if (!(array = ft_strnew(size)))
		return (NULL);
	ft_memset(array, c, size);
	return (array);
}
