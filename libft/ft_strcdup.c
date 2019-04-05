/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:31:33 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/17 15:33:27 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcdup(const char *s, char c)
{
	int		len;
	char	*str;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(str, s, len);
	str[len] = '\0';
	return (str);
}
