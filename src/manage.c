/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:32:42 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/22 15:04:02 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void			move_cursor(int val, t_elem *tmp, t_elem *prev)
{
	if (val == 1)
	{
		tmp->ul = 0;
		if (tmp->next != NULL)
			tmp->next->ul = 1;
	}
	else if (val == 2)
	{
		tmp->ul = 0;
		prev->ul = 1;
	}
}

static void			manage_key(char *buff, t_elem *tmp, t_elem *prev)
{
	if (buff[0] == 27 && buff[1] == 0 && buff[2] == 0 && buff[3] == 0)
		exit_term();
	else if (buff[0] == 32)
	{
		tmp->ul = 0;
		if (tmp->hl == 0)
			tmp->hl = 1;
		else
			tmp->hl = 0;
		if (tmp->next != NULL)
			tmp->next->ul = 1;
	}
	else if (buff[2] == 67)
		move_cursor(1, tmp, prev);
	else if (buff[2] == 68)
		move_cursor(2, tmp, prev);
}

static t_elem		*check_prev(t_elem *tmp, t_elem **e)
{
	t_elem		*prev;

	prev = (*e);
	if (tmp)
	{
		while (prev->nb < (tmp->nb - 1))
			prev = prev->next;
	}
	return (prev);
}

static int			return_pos(t_elem **e)
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

int					manage(char *buff, t_elem **e, int pos)
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
		manage_key(buff, tmp, prev);
	}
	i = return_pos(e);
	return (i);
}
