/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:51:35 by kaboujna          #+#    #+#             */
/*   Updated: 2018/12/05 22:49:01 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

char	*convert_s(t_spec *spec, va_list arg)
{
	char	*conv;

	if (!(conv = va_arg(arg, char *)))
		conv = ft_strdup("(null)");
	else
		conv = ft_strdup(conv);
	if (!ft_strlen(conv) && !spec->precis)
		conv = ft_strjoinfree(conv, " ", 1);
	if (spec->precis < 0)
		spec->precis = ft_strlen(conv);
	conv[spec->precis] = '\0';
	if (spec->champ > (int)ft_strlen(conv))
		gestion_champ(spec, &conv);
	return (conv);
}
