/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 04:27:45 by rfulop            #+#    #+#             */
/*   Updated: 2017/05/27 06:03:53 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

void	putdist(t_room *room, int dist)
{
	int		a;
	t_room	*tmp;
	char	*source;

	a = 0;
	source = ft_strdup(room->name);
	while (room->links && room->links[a])
	{
		tmp = room->links[a];
		if (tmp && !tmp->path && (tmp->dist == -1 || dist < tmp->dist))
		{
			tmp->dist = dist;
			if (tmp->source)
				free(tmp->source);
			tmp->source = ft_strdup(source);
			if (ft_strcmp(tmp->name, room->source))
				putdist(tmp, dist + 1);
		}
		++a;
	}
	free(source);
}

void	cleardist(t_room *begin)
{
	t_room	*tmp;

	tmp = begin;
	while (tmp)
	{
		if (!tmp->path)
			tmp->dist = -1;
		tmp = tmp->next;
	}
}
