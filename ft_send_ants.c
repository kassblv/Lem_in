/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <kaboujna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:08:25 by kaboujna          #+#    #+#             */
/*   Updated: 2019/02/04 17:48:13 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void		print_ants_paths(t_tab *paths)
{
	int		i;
	int		p;

	p = 1;
	ft_printf("\n");
	while (paths)
	{
		i = 0;
		ft_printf("path: ");
		while (paths->path[i])
			ft_printf("%6s ", paths->path[i++]);
		ft_printf("\nants: ");
		i = 0;
		while (paths->ants[i])
			ft_printf("%6s ", paths->ants[i++]);
		ft_printf("\n\n");
		paths = paths->next;
		p++;
	}
}

void		print_move_ant(char *room, char *ant)
{
	if (room)
	{
		ft_putchar('L');
		ft_putstr(ant);
		ft_putchar('-');
		ft_putstr(room);
		ft_putchar(' ');
	}
}

int			allocate_tabs_ants(t_tab *paths, char *no_ant)
{
	int		i;

	if (!paths->path)
	{
		ft_putstr("No path between start and end\n");
		return (0);
	}
	while (paths)
	{
		i = 0;
		while (i < paths->len)
			paths->ants[i++] = no_ant;
		paths->ants[paths->len] = NULL;
		paths = paths->next;
	}
	return (1);
}

void		move_ants(t_tab *path, t_pars *pars, char *no_ant)
{
	int		len;
	int		i;

	while (path)
	{
		len = ft_tablen(path->ants) - 2;
		i = len;
		while (i >= 0)
		{
			if (!ft_strequ(path->ants[i], "0"))
			{
				ft_swap(&path->ants[i], &path->ants[i + 1]);
				if (path->ants[i + 1] && no_ant
				&& (path->ants[i + 1] != no_ant))
					print_move_ant(path->path[i + 1], path->ants[i + 1]);
				if (path->ants[len + 1] != no_ant)
				{
					path->ants[len + 1] = no_ant;
					pars->ants_out++;
				}
			}
			i--;
		}
		path = path->next;
	}
}

void		send_ants(t_pars *pars, t_tab *paths)
{
	t_tab	*path;
	int		ant;

	if (!allocate_tabs_ants(paths, pars->ants[0]))
		return ;
	ant = 1;
	while (pars->ants_out < pars->nb_ants)
	{
		move_ants(pars->goods_paths, pars, pars->ants[0]);
		path = pars->goods_paths;
		while (path && ant <= pars->nb_ants)
		{
			if (path->ants[0] == pars->ants[0])
			{
				print_move_ant(path->path[1], pars->ants[ant]);
				path->ants[1] = pars->ants[ant++];
				if (ft_strequ(path->path[1], pars->room_end))
					pars->ants_out++;
			}
			path = path->next;
		}
		ft_putstr("\n");
	}
}
