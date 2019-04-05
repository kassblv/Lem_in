/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <kaboujna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 16:14:34 by jtaibi            #+#    #+#             */
/*   Updated: 2019/02/04 16:00:31 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_append_tab(char **tab, char *str)
{
	int		var;
	char	**new_tab;

	if (!str)
		return (tab);
	var = ft_tablen(tab);
	if (!(new_tab = (char **)malloc(sizeof(char *) * var + 2)))
		return (NULL);
	var = 0;
	while (tab && tab[var])
	{
		new_tab[var] = tab[var];
		var++;
	}
	new_tab[var] = str;
	new_tab[var + 1] = NULL;
	free(tab);
	return (new_tab);
}
