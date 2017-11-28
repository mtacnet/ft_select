/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:25:18 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/21 14:48:26 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"


/* LIBERER LA MEMOIRE AVANT EXIT ! */

static void		catch_signal(int sig)
{
	t_elem		*e;
	struct winsize		ws;

	e = NULL;
	if (sig == SIGINT)
		exit_term();
	else if (sig == SIGTSTP)
		exit(EXIT_SUCCESS);
	else if (sig == SIGWINCH)
	{
		e = get_arg(NULL);
		ws = get_screen_sz(1);
		ft_putstr_fd(tgetstr("cl", NULL), 0);
		display_list(&e, ws, check_arg_size(&e, ws));
	}
}

void			sig(void)
{
	signal(SIGINT, catch_signal); // Ctrl-C
	signal(SIGTSTP, catch_signal); // Ctrl-Z
	signal(SIGWINCH, catch_signal); // Resize Screen
}
