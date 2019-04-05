/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <kaboujna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:08:09 by kaboujna          #+#    #+#             */
/*   Updated: 2019/02/04 16:08:11 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_lem_in.h"

int			check_alreay_link(t_bond *bonds, char **name)
{
	t_room		*get_name;

	while (bonds)
	{
		get_name = (t_room *)bonds->bond;
		if (ft_strequ(get_name->name, name[0])
		|| ft_strequ(get_name->name, name[1]))
			return (0);
		bonds = bonds->next;
	}
	return (1);
}

void		ft_tfadd(t_tf **alst, t_tf *new)
{
	if (*alst == NULL)
		*alst = new;
	else
	{
		new->next = *alst;
		*alst = new;
	}
}

int			add_new_bonds(t_room *rooms, char **bond, t_tf **fre)
{
	t_room	*tmp;
	t_bond	*append;

	tmp = rooms;
	while (tmp && !ft_strequ(tmp->name, bond[0]))
		tmp = tmp->next;
	if (!check_alreay_link(tmp->bonds, bond))
		return (1);
	while (rooms && !ft_strequ(rooms->name, bond[1]))
		rooms = rooms->next;
	if (!check_alreay_link(rooms->bonds, bond))
		return (1);
	if (!(append = (t_bond*)ft_memalloc(sizeof(t_bond))))
		return (0);
	(*fre)->lib = append;
	append->next = tmp->bonds;
	append->bond = rooms;
	tmp->bonds = append;
	if (!(append = (t_bond*)ft_memalloc(sizeof(t_bond))))
		return (0);
	(*fre)->next->lib = append;
	append->next = rooms->bonds;
	append->bond = tmp;
	rooms->bonds = append;
	return (1);
}

int			check_bond(t_pars *pars, char **bond)
{
	t_tf		*protect;
	int			check_bond;
	t_room		*room;

	check_bond = 0;
	room = pars->rooms;
	while (room)
	{
		if (ft_strequ(bond[0], room->name) || ft_strequ(bond[1], room->name))
			check_bond++;
		room = room->next;
	}
	if (check_bond != 2)
		return (1);
	if (!(protect = (t_tf*)ft_memalloc(sizeof(t_tf))))
		exit(0);
	ft_tfadd(&pars->fre, protect);
	if (!(protect = (t_tf*)ft_memalloc(sizeof(t_tf))))
		exit(0);
	ft_tfadd(&pars->fre, protect);
	add_new_bonds(pars->rooms, bond, &pars->fre);
	return (1);
}

int			get_bonds(t_pars *pars, char *line)
{
	char **bond;

	while (1)
	{
		if (!line && get_next_line(0, &line) <= 0)
		{
			ft_strdel(&line);
			break ;
		}
		if (!(bond = ft_strsplit(line, '-')))
			return (0);
		if (ft_tablen(bond) < 2 || !check_bond(pars, bond))
		{
			ft_strdel(&line);
			ft_free_tab(bond);
			return (0);
		}
		ft_strdel(&line);
		ft_free_tab(bond);
	}
	ft_strdel(&line);
	return (1);
}
