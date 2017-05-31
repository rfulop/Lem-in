/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 04:27:45 by rfulop            #+#    #+#             */
/*   Updated: 2017/05/31 18:56:28 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

void	free_list(t_room *begin)
{
	t_room	*tmp;

	while (begin)
	{
		free(begin->source);
		free(begin->name);
		free(begin->links);
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
}

void	solve(t_lemin *core, t_room *begin)
{
	if (!core->start || !core->end || !begin ||
		(!(ft_strcmp(core->start->name, core->end->name))))
		error();
	core->end->source = ft_strdup(core->end->name);
	core->end->dist = 0;
	putdist(core->end, 1);
	if (core->start->dist == -1)
		error(NULL);
	ft_printf("%s\n", core->displayline);
	free(core->displayline);
	pathnumber(core, begin);
	mooveants(core, begin);
	free_list(begin);
	exit(1);
}

char	*display_line(char *display, char *str)
{
	char	*new;

	new = NULL;
	if (!display)
	{
		display = ft_strnew(ft_strlen(str) + 1);
		display = ft_strcpy(display, str);
		display = ft_strcat(display, "\n");
	}
	else
	{
		if (!(new = (char*)malloc(sizeof(char) * ft_strlen(display) +
		ft_strlen(str) + 2)))
			error();
		new[ft_strlen(display + ft_strlen(str))] = '\n';
		new[ft_strlen(display + ft_strlen(str) + 1)] = '\0';
		new = ft_strcpy(new, display);
		new = ft_strcat(new, str);
		new = ft_strcat(new, "\n");
		free(display);
		display = ft_strdup(new);
		free(new);
	}
	return (display);
}

t_room	*parse(t_lemin *core, t_room *room, char *line)
{
	if (!core->init)
		init_core(core, line);
	else if (line[0] == '#' && line[1] == '#')
		room = init_startend(core, &room, line, 0);
	else if (*line == '#')
		core->displayline = display_line(core->displayline, line);
	else if (ft_findstr(line, "-"))
		init_link(core, &room, line);
	else
		room = init_room(core, &room, line);
	return (room);
}

int		main(int argc, char **argv)
{
	t_lemin		core;
	t_room		*room;
	char		*line;

	(void)argv;
	if (argc != 1)
		error();
	line = NULL;
	room = NULL;
	core.init = 0;
	core.displayline = NULL;
	while (get_next_line(0, &line) > 0)
	{
		room = parse(&core, room, line);
		free(line);
	}
	solve(&core, room);
	return (0);
}
