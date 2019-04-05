/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_rooms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <kaboujna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:08:18 by kaboujna          #+#    #+#             */
/*   Updated: 2019/02/04 17:31:21 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"
#include "libft/libft.h"

t_room		*create_new_room(char **infos_room)
{
	t_room		*new_room;

	if (!(new_room = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	new_room->name = infos_room[0];
	new_room->x = infos_room[1];
	new_room->y = infos_room[2];
	new_room->mark = 0;
	new_room->next = NULL;
	return (new_room);
}

t_room		*check_room(t_pars *pars, t_room *rooms, char **infos_room)
{
	t_room		*new_room;

	while (rooms)
	{
		if (ft_strequ(infos_room[0], rooms->name))
		{
			ft_putstr("\nTwo rooms can't have the same name.\n");
			return (NULL);
		}
		if (ft_strequ(infos_room[1], rooms->x)
		&& ft_strequ(infos_room[2], rooms->y))
		{
			ft_putstr("\nTwo rooms can't be superposed.\n");
			return (NULL);
		}
		if (!ft_isnumber(infos_room[1]) || !ft_isnumber(infos_room[2]))
		{
			ft_putstr("\nCoordinates are not valid.\n");
			return (NULL);
		}
		rooms = rooms->next;
	}
	new_room = create_new_room(infos_room);
	attribute_start_or_end(pars, infos_room[0]);
	return (new_room);
}

int			add_new_room(t_pars *pars, char **infos_room)
{
	t_room		*new_room;

	if (!(new_room = check_room(pars, pars->rooms, infos_room)))
	{
		ft_free_tab(infos_room);
		return (0);
	}
	if (pars->rooms)
	{
		new_room->next = pars->rooms;
		pars->rooms = new_room;
		pars->nb_rooms++;
	}
	else if ((pars->rooms = new_room))
		pars->nb_rooms = 1;
	new_room->bonds = NULL;
	return (1);
}

int			get_rooms2(char **line, char **infos_room)
{
	if (ft_tablen(infos_room) < 3 || ft_tablen(infos_room) > 3)
	{
		if (ft_tablen(infos_room) < 3)
			ft_putstr("\nData missing.\n");
		else
			ft_putstr("\nTo much data.\n");
		ft_strdel(line);
		ft_free_tab(infos_room);
		return (0);
	}
	if (!ft_isdigit(infos_room[1][0]) || !ft_isdigit(infos_room[2][0]))
	{
		ft_free_tab(infos_room);
		ft_putstr("\nCoordinates must be numbers.\n");
		return (0);
	}
	return (1);
}

int			get_rooms(t_pars *pars, char **line)
{
	char		**infos_room;

	while (1)
	{
		ft_strdel(line);
		if (get_next_line(0, line) <= 0 || !ft_strlen(*line)
				|| ft_strchr(*line, '-'))
			break ;
		if (**line == '#' && check_start_end(pars, *line))
			continue ;
		if (!(infos_room = ft_strsplit(*line, ' ')))
			return (0);
		if (!(get_rooms2(line, infos_room)))
			return (0);
		if (!add_new_room(pars, infos_room))
		{
			ft_strdel(line);
			return (0);
		}
		if (infos_room)
			free(infos_room);
	}
	return (1);
}
