/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:57:26 by mtacnet           #+#    #+#             */
/*   Updated: 2017/12/02 15:08:43 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void		manage_key(char *buff, t_elem *tmp, t_elem *prev, t_elem **e)
{
	if (buff[0] == 27 && buff[1] == 0 && buff[2] == 0 && buff[3] == 0)
		exit_term(1);
	else if (buff[0] == 32)
		move_cursor(3, tmp, prev, e);
	else if (buff[0] == 127)
		move_cursor(4, tmp, prev, e);
	else if (buff[2] == 67)
		move_cursor(1, tmp, prev, e);
	else if (buff[2] == 68)
		move_cursor(2, tmp, prev, e);
}

static int		return_pos(t_elem **e)
{
	int			i;
	t_elem		*tmp;

	i = 1;
	tmp = (*e);
	while (tmp->next != NULL && tmp->ul != 1)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int				manage(char *buff, t_elem **e, int pos)
{
	t_elem		*tmp;
	t_elem		*prev;
	int			i;

	i = 0;
	prev = NULL;
	tmp = (*e);
	while (tmp && tmp->nb < pos)
	{
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
	if (tmp != NULL)
	{
		prev = check_prev(tmp, e);
		manage_key(buff, tmp, prev, e);
	}
	i = return_pos(e);
	return (i);
}
