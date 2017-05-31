/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 04:27:45 by rfulop            #+#    #+#             */
/*   Updated: 2017/05/30 20:51:06 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

void	init_linktab(t_lemin *core, t_room *room)
{
	int a;

	a = 0;
	while (a < core->i)
	{
		room->links[a] = NULL;
		a++;
	}
}

t_room	*addnum(t_lemin *core, t_room *room, t_room *dest)
{
	int	a;

	a = 0;
	core->initlinks = 1;
	if (!room->links)
	{
		if (!(room->links = (t_room**)malloc(sizeof(t_room*) * (core->i))))
			error();
		init_linktab(core, room);
	}
	else
	{
		while (room->links[a] != NULL)
		{
			if (room->links[a] == dest)
				return (room);
			++a;
		}
	}
	room->links[a] = dest;
	return (room);
}

void	init_link(t_lemin *core, t_room **room, char *line)
{
	char	*name_src;
	char	*name_dest;
	t_room	*tmp;
	t_room	*tmp2;

	tmp = *room;
	tmp2 = *room;
	name_src = ft_strnewchr(line, '-');
	name_dest = ft_strnewchr(line + ft_strlen(name_src) + 1, '\0');
	while (tmp && ft_strcmp(tmp->name, name_dest))
		tmp = tmp->next;
	while (tmp2 && ft_strcmp(tmp2->name, name_src))
		tmp2 = tmp2->next;
	if (!tmp || !tmp2)
	{
		free(name_dest);
		free(name_src);
		solve(core, *room);
	}
	tmp2 = addnum(core, tmp2, tmp);
	tmp = addnum(core, tmp, tmp2);
	free(name_dest);
	free(name_src);
	core->displayline = display_line(core->displayline, line);
}
