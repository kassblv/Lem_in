/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <kaboujna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:07:43 by kaboujna          #+#    #+#             */
/*   Updated: 2019/02/04 17:41:34 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static char		**get_names_ants(int nb)
{
	int		ant;
	char	**ants;

	ant = 0;
	if (!(ants = (char **)ft_memalloc(sizeof(char *) * (nb + 2))))
		return (NULL);
	ants[ant++] = ft_strdup("0");
	while (ant <= nb)
	{
		ants[ant] = ft_itoa(ant);
		ant++;
	}
	ants[ant] = NULL;
	return (ants);
}

static void		init_pars(t_pars *pars)
{
	pars->nb_ants = 0;
	pars->flag_start = 0;
	pars->flag_end = 0;
	pars->ipath = 0;
	pars->fre = NULL;
	pars->rooms = NULL;
	pars->paths = NULL;
	pars->last_room = NULL;
	pars->nb_rooms = 0;
	pars->goods_paths = NULL;
	pars->ants_out = 0;
	pars->room_start = NULL;
	pars->room_end = NULL;
}

int				main2(t_pars *pars, char **line)
{
	if (!(get_rooms(pars, line)))
	{
		free_rooms(pars->rooms);
		ft_free_tab(pars->ants);
		return (-1);
	}
	if (!*line || !ft_strchr(*line, '-'))
	{
		free_rooms(pars->rooms);
		ft_free_tab(pars->ants);
		ft_putstr("\nNo links between rooms.\n");
		return (-1);
	}
	return (1);
}

int				main3(t_pars *pars, char **line)
{
	if (pars->room_start && pars->room_end)
	{
		get_bonds(pars, *line);
		get_paths(pars);
		if (!pars->good_paths)
			ft_putstr("\nNo path between start and end found.\n");
		else
		{
			init_paths(pars);
			send_ants(pars, pars->goods_paths);
		}
		free_routine(pars);
	}
	else
	{
		free_rooms(pars->rooms);
		ft_free_tab(pars->ants);
		ft_strdel(line);
		ft_putstr("\nNo room start or end.\n");
	}
	return (1);
}

int				main(void)
{
	char		*line;
	t_pars		pars;

	line = NULL;
	init_pars(&pars);
	if (get_next_line(0, &line) <= 0 || !ft_isnumber(line) || !ft_strlen(line))
	{
		if (line)
			ft_strdel(&line);
		return (-1);
	}
	pars.nb_ants = ft_atoi(line);
	if (!pars.nb_ants || pars.nb_ants < 0 || pars.nb_ants > INT16_MAX
	|| pars.nb_ants < INT16_MIN || !ft_isnumber(line))
	{
		ft_strdel(&line);
		ft_putstr("\nBad number of ants.\n");
		return (-1);
	}
	if (!(pars.ants = get_names_ants(pars.nb_ants)))
		return (-1);
	if (main2(&pars, &line) == -1)
		return (-1);
	main3(&pars, &line);
	return (1);
}
