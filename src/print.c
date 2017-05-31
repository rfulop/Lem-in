/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 04:27:45 by rfulop            #+#    #+#             */
/*   Updated: 2017/05/31 18:45:29 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

void	error(void)
{
	ft_printf("ERROR\n");
	exit(-1);
}

void	printmoove(t_lemin *core, t_room *dest, int ant)
{
	if (dest->id == core->end->id)
		core->ants_end++;
	if (!ant)
	{
		dest->ant = core->antnum;
		core->antnum++;
	}
	else
		dest->ant = ant;
	ft_printf("L%d-%s", dest->ant, dest->name);
}
