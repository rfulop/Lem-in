/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 04:27:45 by rfulop            #+#    #+#             */
/*   Updated: 2017/05/27 06:38:25 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		maxpath(t_lemin *core)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (!core->end->links || !core->start->links)
		error();
	while (core->end->links[a])
		++a;
	while (core->start->links[b])
		++b;
	return (a < b ? a : b);
}

int		checkpath(t_lemin *core, t_room *room, int dist)
{
	int		a;
	t_room	*path;
	t_room	*tmp;

	while (room->links && (room->id != core->end->id))
	{
		path = NULL;
		a = 0;
		dist = -1;
		while (room->links && room->links[a])
		{
			tmp = room->links[a++];
			if ((dist == -1 || tmp->dist <= dist) && !tmp->path)
			{
				path = tmp;
				dist = tmp->dist;
			}
		}
		if (!path)
			return (0);
		path->path = core->paths;
		core->sizepath++;
		room = path;
	}
	return (1);
}

void	pathnumber(t_lemin *core, t_room *begin)
{
	int	max;

	max = maxpath(core);
	core->paths = 1;
	core->end->path = 0;
	core->start->path = 1;
	checkpath(core, core->start, 0);
	cleardist(begin);
	putdist(core->end, 1);
	core->paths++;
	while (core->paths <= max && (core->ants > core->sizepath))
	{
		core->end->path = 0;
		core->start->path = 1;
		if (checkpath(core, core->start, 0))
			core->paths++;
		else
			max--;
		cleardist(begin);
		putdist(core->end, 1);
	}
}
