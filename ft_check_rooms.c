/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:37:05 by kaboujna          #+#    #+#             */
/*   Updated: 2019/02/04 17:37:18 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void		attribute_start_or_end(t_pars *pars, char *name)
{
	if (pars->flag_start == 1)
	{
		pars->room_start = name;
		pars->flag_start = 0;
	}
	if (pars->flag_end == 1)
	{
		pars->room_end = name;
		pars->flag_end = 0;
	}
}

int			check_start_end(t_pars *pars, char *line)
{
	if (ft_strequ(line, "##start"))
	{
		pars->flag_start = 1;
		pars->flag_end = 0;
	}
	else if (ft_strequ(line, "##end"))
	{
		pars->flag_end = 1;
		pars->flag_start = 0;
	}
	return (1);
}
