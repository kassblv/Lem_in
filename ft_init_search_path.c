/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_search_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:37:49 by kaboujna          #+#    #+#             */
/*   Updated: 2019/02/04 17:38:05 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static void		init_paths2(t_tab *paths)
{
	paths->path = NULL;
	paths->len = 0;
	paths->next = NULL;
}

void			init_paths(t_pars *pars)
{
	int			i;
	int			a;
	t_tab		*paths;

	if (!(pars->goods_paths = (t_tab *)ft_memalloc(sizeof(t_tab))))
		exit(0);
	init_paths2((paths = pars->goods_paths));
	i = 0;
	while (pars->good_paths[i])
	{
		paths->path = ft_strsplit(pars->good_paths[i], ' ');
		paths->len = ft_tablen(paths->path);
		paths->ants = (char **)ft_memalloc(sizeof(char *) * (paths->len + 1));
		a = 0;
		while (a < paths->len)
			paths->ants[a++] = "0";
		paths->ants[a] = NULL;
		if (pars->good_paths[i + 1])
		{
			paths->next = (t_tab *)ft_memalloc(sizeof(t_tab));
			paths = paths->next;
			paths->next = NULL;
		}
		i++;
	}
}
