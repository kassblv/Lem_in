/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <kaboujna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 09:09:27 by kaboujna          #+#    #+#             */
/*   Updated: 2019/02/04 15:58:50 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
	{
		if (tab[i])
			free(tab[i]);
	}
	free(tab);
}
