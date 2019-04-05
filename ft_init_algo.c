/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <kaboujna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:07:55 by kaboujna          #+#    #+#             */
/*   Updated: 2019/02/04 16:07:58 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int			is_not_past(char *find, char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(str, ' ');
	while (tab[i])
	{
		if (ft_strequ(tab[i], find))
		{
			ft_free_tab(tab);
			return (0);
		}
		i++;
	}
	ft_free_tab(tab);
	return (1);
}

char		*add_new_path(t_pars *pars)
{
	t_room	*course;
	t_room	*next_room;
	t_bond	*bonds;
	char	*new_path;

	course = pars->rooms;
	new_path = ft_strjoinfree(ft_strdup(pars->room_start), " ", 1);
	while (course->name != pars->room_end)
	{
		bonds = course->bonds;
		while (bonds && course->name != pars->room_end)
		{
			next_room = (t_room *)bonds->bond;
			if (is_not_past(next_room->name, new_path)
					&& next_room->mark == pars->nb_path)
			{
				course = (t_room *)bonds->bond;
				new_path = ft_strjoinfree(new_path, course->name, 1);
				new_path = ft_strjoinfree(new_path, " ", 1);
			}
			bonds = bonds->next;
		}
	}
	pars->last_room->mark = 0;
	return (new_path);
}

void		init_algo(t_pars *pars)
{
	int			len;
	t_bond		*bonds;

	pars->last_room = pars->rooms;
	while (pars && pars->last_room && pars->last_room->name != pars->room_end)
		pars->last_room = pars->last_room->next;
	pars->room_free = pars->rooms;
	while (pars->rooms->name != pars->room_start)
		pars->rooms = pars->rooms->next;
	pars->nb_path = 0;
	pars->rooms->mark = -1;
	if (!(pars->paths = (t_mpath *)ft_memalloc(sizeof(t_mpath))))
		return ;
	pars->paths->path = NULL;
	pars->paths->next = NULL;
	bonds = pars->rooms->bonds;
	len = 0;
	while (bonds)
	{
		bonds = bonds->next;
		len++;
	}
	if (!(pars->good_paths = ft_memalloc(sizeof(char *) * (len + 1))))
		exit(0);
	pars->ipath = 0;
}
