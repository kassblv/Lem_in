/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <kaboujna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:07:36 by kaboujna          #+#    #+#             */
/*   Updated: 2019/02/04 16:07:40 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static void		free_bonds(t_tf *to_free)
{
	t_tf		*save;

	while (to_free)
	{
		save = to_free;
		to_free = to_free->next;
		free(save->lib);
		free(save);
	}
}

void			free_rooms(t_room *rooms)
{
	t_room		*save;

	while (rooms)
	{
		save = rooms;
		rooms = rooms->next;
		free(save->name);
		free(save->x);
		free(save->y);
		free(save);
	}
}

static void		free_mpath(t_mpath *allpath)
{
	t_mpath	*save;

	while (allpath)
	{
		save = allpath;
		allpath = allpath->next;
		free(save->path);
		free(save);
	}
}

static void		free_tab(t_tab *tab)
{
	t_tab *save;

	while (tab)
	{
		save = tab;
		tab = tab->next;
		free(save->ants);
		ft_free_tab(save->path);
		free(save);
	}
}

void			free_routine(t_pars *pars)
{
	pars->rooms = pars->room_free;
	free_bonds(pars->fre);
	free_tab(pars->goods_paths);
	free_mpath(pars->paths);
	ft_free_tab(pars->ants);
	ft_free_tab(pars->good_paths);
	free_rooms(pars->rooms);
}
