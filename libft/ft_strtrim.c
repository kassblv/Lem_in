/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:19:34 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/16 01:19:34 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compte(char const *s, int i, int lens)
{
	int	len;

	len = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i--;
		len++;
	}
	while (*s == ' ' || *s == '\t' || *s == '\n')
	{
		s++;
		len++;
	}
	if (*s == '\0')
		len = lens;
	return (len);
}

char		*ft_strtrim(char const *s)
{
	int		len2;
	char	*str;
	int		i;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	i = len - 1;
	len2 = ft_compte(s, i, len);
	str = (char*)malloc(sizeof(char) * (len - len2 + 1));
	if (str == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	i = 0;
	while (s[i] != '\0' && i < len - len2)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
