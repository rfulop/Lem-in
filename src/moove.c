/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 04:27:45 by rfulop            #+#    #+#             */
/*   Updated: 2017/05/29 01:58:19 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

t_room	*findplace(t_room *from, int path)
{
	int		a;
	int		dist;
	t_room	*tmp;
	t_room	*dest;

	a = 0;
	dist = -1;
	while (from->links[a])
	{
		tmp = from->links[a];
		if ((tmp->path == path || tmp->path == -1) &&
		(dist < 0 || tmp->dist < dist))
		{
			dist = tmp->dist;
			dest = tmp;
		}
		++a;
	}
	return (dest);
}

void	moovefromstart(t_lemin *core)
{
	int		path;
	t_room	*dest;

	path = 1;
	while (core->ants_start && path != core->paths)
	{
		dest = findplace(core->start, path);
		printmoove(core, dest, 0);
		core->ants_start--;
		path++;
		if (path != core->paths)
			ft_printf(" ");
	}
	ft_printf("\n");
}

void	moovefromrooms(t_lemin *core, t_room *begin)
{
	int		a;
	int		flag;
	t_room	*room;
	t_room	*dest;

	a = 1;
	while (a <= ((core->ants - core->ants_start) + core->ants_end))
	{
		room = begin;
		flag = 0;
		while (room && !flag)
		{
			if (room->ant == a && (room->id != core->end->id))
			{
				dest = findplace(room, room->path);
				printmoove(core, dest, room->ant);
				if (a != core->ants)
					ft_printf(" ");
				room->ant = 0;
				++flag;
			}
			room = room->next;
		}
		++a;
	}
}

void	mooveants(t_lemin *core, t_room *begin)
{
	core->end->path = -1;
	core->start->path = 0;
	while (core->ants_end != core->ants)
	{
		moovefromrooms(core, begin);
		moovefromstart(core);
	}
}
