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
	if (sig == SIGINT)
		exit_term();
	else if (sig == SIGTSTP)
		exit(EXIT_SUCCESS);
	else if (sig == SIGWINCH)
		ft_putendl_fd("RESIZE", 1);
}

void			sig(void)
{
	signal(SIGINT, catch_signal); // Ctrl-C
	signal(SIGTSTP, catch_signal); // Ctrl-Z
	signal(SIGWINCH, catch_signal); // Resize Screen
}
