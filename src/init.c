/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 04:27:45 by rfulop            #+#    #+#             */
/*   Updated: 2017/05/31 19:36:02 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		check_room(char *line)
{
	int	a;

	a = (int)ft_strlen(line) - 1;
	while (line[a] != ' ')
	{
		if (!ft_isdigit(line[a]))
			return (0);
		a--;
	}
	a--;
	while (line[a] != ' ')
	{
		if (!ft_isdigit(line[a]))
			return (0);
		a--;
	}
	return (line[a - 1] ? a : 0);
}

t_room	*init_room(t_lemin *core, t_room **room, char *line)
{
	int		a;
	t_room	*tmp;

	a = check_room(line);
	if (ft_findstr(line, "-") || *line == '#' || *line == 'L' || !a ||
		*line == '\0' || core->initlinks)
		solve(core, *room);
	tmp = *room;
	while (tmp)
		tmp = tmp->next;
	if (!(tmp = (t_room*)malloc(sizeof(t_room))))
		error(NULL);
	tmp->name = ft_strndup(line, a);
	tmp->source = NULL;
	tmp->id = core->i++;
	tmp->dist = -1;
	tmp->ant = 0;
	tmp->path = 0;
	tmp->links = NULL;
	tmp->next = *room;
	core->displayline = display_line(core->displayline, line);
	return (tmp);
}

t_room	*init_startend(t_lemin *core, t_room **room, char *line, int fd)
{
	int		i;
	t_room	*new;

	new = NULL;
	if (!(ft_strcmp(line, "##start")))
		i = 1;
	else if (!(ft_strcmp(line, "##end")))
		i = 2;
	else
		return (*room);
	core->displayline = display_line(core->displayline, line);
	if (get_next_line(fd, &line) <= 0)
		error();
	new = init_room(core, room, line);
	if (i == 1)
		core->start = new;
	else
		core->end = new;
	free(line);
	return (new);
}

void	init_vars(t_lemin *core, char *line)
{
	core->ants_start = core->ants;
	core->ants_end = 0;
	core->init = 1;
	core->initlinks = 0;
	core->i = 1;
	core->antnum = 1;
	core->start = NULL;
	core->end = NULL;
	core->sizepath = 0;
	core->displayline = display_line(core->displayline, line);
}

void	init_core(t_lemin *core, char *line)
{
	int a;

	a = 0;
	if (!line)
		error();
	if (*line != '#')
	{
		while (line[a])
		{
			if (!(ft_isdigit(line[a])))
			{
				free(line);
				error();
			}
			++a;
		}
		core->ants = ft_atoi(line);
		if (core->ants <= 0)
			error();
		init_vars(core, line);
	}
	else if (*line == '#' && line[1] != '#')
		core->displayline = display_line(core->displayline, line);
}
