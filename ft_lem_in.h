/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <kaboujna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:08:46 by kaboujna          #+#    #+#             */
/*   Updated: 2019/02/04 17:35:25 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# define STEP_ROOMS	1
# define STEP_BONDS	2

# include "libft/libft.h"

typedef struct		s_tf
{
	void			*lib;
	struct s_tf		*next;
}					t_tf;

typedef struct		s_bond
{
	void			*bond;
	struct s_bond	*next;
}					t_bond;

typedef struct		s_room
{
	char			*name;
	char			*y;
	char			*x;
	int				mark;
	t_bond			*bonds;
	struct s_room	*next;
}					t_room;

typedef struct		s_path
{
	char			*name;
	struct s_path	*next;
}					t_path;

typedef struct		s_mpath
{
	t_path			*path;
	struct s_mpath	*next;
}					t_mpath;

typedef struct		s_tab
{
	int				len;
	char			**path;
	char			**ants;
	struct s_tab	*next;
}					t_tab;

typedef struct		s_pars
{
	int				nb_ants;
	int				ants_out;
	int				flag_start;
	int				flag_end;
	int				flag_step;
	int				nb_rooms;
	int				stop;
	int				nb_path;
	int				ipath;
	char			**ants;
	char			*room_start;
	char			*room_end;
	char			**good_paths;
	t_room			*room_free;
	t_room			*rooms;
	t_room			*last_room;
	t_mpath			*paths;
	t_tab			*goods_paths;
	t_tf			*fre;
}					t_pars;
/*
**		parsing rooms
*/
int					get_rooms(t_pars *pars, char **line_read);
int					add_new_room(t_pars *pars, char **infos_room);
int					check_start_end(t_pars *pars, char *line);
t_room				*check_room(t_pars *pars, t_room *rooms, char **infos_room);
void				attribute_start_or_end(t_pars *pars, char *name);
/*
**		parsing bonds
*/
int					get_bonds(t_pars *pars, char *line);
int					check_bond(t_pars *pars, char **bond);
/*
**		search paths
*/
void				init_paths(t_pars *pars);
int					is_not_past(char *find, char *str);
int					is_valid(char **tab, int mark);
void				get_paths(t_pars *pars);
void				init_algo(t_pars *pars);
char				*add_new_path(t_pars *pars);
void				depth_first_search(t_room *room, t_path *path, t_pars *pars,
char *excludes);
t_room				*get_room(t_room *rooms, char *name);
/*
**		manage paths
*/
void				print_paths(t_pars *pars);
/*
**		send ants
*/
void				send_ants(t_pars *pars, t_tab *paths);
/*
**		free routine
*/
void				free_rooms(t_room *rooms);
void				free_routine(t_pars *pars);

#endif
