/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 02:50:51 by rfulop            #+#    #+#             */
/*   Updated: 2017/05/30 20:52:19 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "./../libft/includes/libft.h"
# include "./../libft/includes/ft_printf.h"

typedef struct		s_room
{
	int				id;
	char			*name;
	int				ant;
	int				dist;
	int				path;
	char			*source;
	struct s_room	**links;
	struct s_room	*next;
}					t_room;

typedef struct		s_lemin
{
	int				i;
	int				init;
	int				initlinks;
	int				ants;
	int				antnum;
	int				ants_start;
	int				ants_end;
	int				paths;
	int				sizepath;
	struct s_room	*start;
	struct s_room	*end;
	char			*displayline;
}					t_lemin;

/*
 ** Main functions
*/
t_room				*parse(t_lemin *core, t_room *room, char *line);
void				solve(t_lemin *core, t_room *begin);
char				*display_line(char *display, char *str);
void				free_list(t_room *begin);

/*
 ** Init functions
*/
void				init_core(t_lemin *core, char *line);
void				init_vars(t_lemin *core, char *line);
t_room				*init_startend(t_lemin *core, t_room **room, char *line,
					int fd);
t_room				*init_room(t_lemin *core, t_room **room, char *line);

/*
 ** Links functions
*/
void				init_linktab(t_lemin *core, t_room *room);
t_room				*addnum(t_lemin *core, t_room *room, t_room *dest);
void				init_link(t_lemin *core, t_room **room, char *line);

/*
 ** Distance functions
*/
void				putdist(t_room *room, int dist);
void				cleardist(t_room *begin);

/*
 ** Paths functions
*/
int					maxpath(t_lemin *core);
int					checkpath(t_lemin *core, t_room *room, int fd);
void				pathnumber(t_lemin *core, t_room *begin);

/*
 ** Moove functions
*/
t_room				*findplace(t_room *from, int path);
void				moovefromstart(t_lemin *core);
void				moovefromrooms(t_lemin *core, t_room *begin);
void				printmoove(t_lemin *core, t_room *dest, int ant);

/*
 ** Print functions
*/
void				error();
void				mooveants(t_lemin *core, t_room *begin);

/*
 ** Debug functions
*/
void				printinttab(t_room *room);
void				printall(t_room *begin);

#endif
