/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_termcap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:38:33 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/06 16:23:02 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void		exit_term(t_elem **e, struct termios **origin)
{
	**origin = (*e)->term;
	if (tcsetattr(0, TCSANOW, *origin) == -1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

void			display_list(t_elem **e)
{
	char	*res;

	if ((res = tgetstr("cl", NULL)) == NULL)
		exit(EXIT_FAILURE);
	ft_putstr(res);
	view_llist(e);
}

void			move_cursor(int val)
{
	char	*res;

	res = NULL;
	if (val == 1)
		res = tgetstr("le", NULL);
	else if (val == 2)
		res = tgetstr("nd", NULL);
	else if (val == 3)
		res = tgetstr("up", NULL);
	else if (val == 4)
		res = tgetstr("do", NULL);
	if (res == NULL)
		exit(EXIT_FAILURE);
	else
		ft_putstr(res);
}

void			man_termcap(int val, t_elem **e, struct termios **origin)
{
	if (val == 0)
		exit_term(e, origin);
}
