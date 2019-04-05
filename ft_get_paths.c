/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <kaboujna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:08:39 by kaboujna          #+#    #+#             */
/*   Updated: 2019/02/04 16:08:40 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

t_path		*new_path(char *name)
{
	t_path	*path;

	if (!(path = (t_path *)ft_memalloc(sizeof(t_path))))
		return (NULL);
	path->name = name;
	path->next = NULL;
	return (path);
}

void		depth_first_search(t_room *room, t_path *path, t_pars *pars,
char *tmp)
{
	char		*excludes;
	t_bond		*bonds;

	excludes = NULL;
	bonds = room->bonds;
	if (room->name != pars->room_end)
	{
		excludes = ft_strjoinfree(ft_strdup(tmp), " ", 1);
		excludes = ft_strjoinfree(excludes, room->name, 1);
		while (excludes && bonds)
		{
			if (excludes && is_not_past(((t_room *)bonds->bond)->name, excludes)
					&& pars->stop == 0 && ((t_room *)bonds->bond)->mark == 0)
				depth_first_search((t_room *)bonds->bond, path, pars, excludes);
			if (pars->stop == 1)
				break ;
			bonds = bonds->next;
		}
	}
	else
		pars->stop = 1;
	if (pars->stop == 1)
		room->mark = pars->nb_path;
	ft_strdel(&excludes);
}

void		search_path(t_pars *pars, t_mpath *tmp, t_bond *tmp2)
{
	char	*excludes;

	pars->stop = 0;
	pars->nb_path++;
	excludes = NULL;
	excludes = ft_strjoin(pars->room_start, " ");
	depth_first_search((t_room *)tmp2->bond, tmp->path, pars, excludes);
	ft_strdel(&excludes);
}

void		get_paths(t_pars *pars)
{
	t_mpath		*tmp;
	t_bond		*tmp2;

	init_algo(pars);
	tmp = pars->paths;
	tmp2 = pars->rooms->bonds;
	pars->last_room->mark = 0;
	while (tmp2)
	{
		search_path(pars, tmp, tmp2);
		if (pars->stop == 1)
			pars->good_paths[pars->ipath++] = add_new_path(pars);
		if ((tmp2 = tmp2->next))
		{
			if (!(tmp->next = (t_mpath *)ft_memalloc(sizeof(t_mpath))))
				return ;
			tmp->next->path = new_path(pars->room_start);
			tmp->next->next = NULL;
		}
		else
			tmp->next = NULL;
		tmp = tmp->next;
	}
	pars->good_paths[pars->ipath] = NULL;
}
