/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:58:35 by mtacnet           #+#    #+#             */
/*   Updated: 2017/12/04 12:21:53 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

t_elem		*check_prev(t_elem *tmp, t_elem **e)
{
	t_elem		*prev;

	prev = (*e);
	if (tmp)
	{
		if ((tmp->nb - 1) < 1)
			prev = last_elem(e);
		else
			while (prev->nb < (tmp->nb - 1))
				prev = prev->next;
	}
	if (prev->del == 0)
		return (prev);
	else
		return (check_prev(prev, e));
}

t_elem		*check_next(t_elem *tmp)
{
	t_elem		*next;

	next = NULL;
	if (tmp)
	{
		next = tmp;
		while (next->next != NULL && next->del == 1)
			next = next->next;
	}
	if (next && next->del == 0)
		return (next);
	else
		return (NULL);
}

t_elem		*last_elem(t_elem **e)
{
	t_elem		*tmp;

	tmp = (*e);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void		reset_term(void)
{
	struct termios		tm;

	tm = get_term(4);
	if (tcsetattr(0, TCSADRAIN, &tm) == -1)
		exit(EXIT_FAILURE);
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	ft_putstr_fd(tgetstr("te", NULL), 0);
	ft_putstr_fd(tgetstr("ve", NULL), 0);
}
