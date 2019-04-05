/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <kaboujna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:21:39 by afrancoi          #+#    #+#             */
/*   Updated: 2019/02/04 17:52:22 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 4096

int				get_next_line(const int fd, char **line);

typedef	struct	s_save
{
	int				fd;
	char			*str;
	struct s_save	*next;
}				t_save;

#endif
