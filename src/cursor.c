/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:57:00 by mtacnet           #+#    #+#             */
/*   Updated: 2017/12/09 11:48:41 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void		remove_elem(t_elem *tmp, t_elem **e, t_elem *prev)
{
	tmp->ul = 0;
	tmp->del = 1;
	move_cursor(1, tmp, prev, e);
}

static void		select_elem(t_elem *tmp, t_elem **e, t_elem *prev)
{
	tmp->ul = 0;
	if (tmp->hl == 0)
		tmp->hl = 1;
	else
		tmp->hl = 0;
	move_cursor(1, tmp, prev, e);
}

void			display_elem(t_elem **e)
{
	t_elem		*tmp;
	int			i;

	tmp = (*e);
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	reset_term();
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->hl == 1 && tmp->del == 0)
		{
			if (i != 0)
				ft_putstr_fd(" ", 1);
			ft_putstr_fd(tmp->content, 1);
			i++;
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
	exit(EXIT_SUCCESS);
}

void			move_cursor(int val, t_elem *tmp, t_elem *prev, t_elem **e)
{
	t_elem		*head;

	head = (*e);
	if (val == 1)
	{
		empty_list(e);
		tmp->ul = 0;
		if (!(tmp = check_next(tmp->next)))
			tmp = check_next(head);
		tmp->ul = 1;
	}
	else if (val == 2)
	{
		tmp->ul = 0;
		prev->ul = 1;
	}
	else if (val == 3)
		select_elem(tmp, e, prev);
	else if (val == 4)
		remove_elem(tmp, e, prev);
}
