/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_termcap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:38:33 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/06 14:37:26 by mtacnet          ###   ########.fr       */
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

/*void			display_list(t_elem **e)
{
	char	*res;

	if ((res = tgetstr("cl", NULL)) == NULL)
		exit(EXIT_FAILURE);
	ft_putstr(res);
	view_llist(e);
}*/

void			man_termcap(int val, t_elem **e, struct termios **origin)
{
	if (val == 0)
		exit_term(e, origin);
}
