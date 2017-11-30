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

static void		catch_exit_sig(int sig)
{
	if (sig)
		exit_term();
}

static void		catch_resize_signal(int sig)
{
	t_elem		*e;
	struct winsize		ws;

	e = NULL;
	if (sig == SIGWINCH)
	{
		e = get_arg(NULL);
		ws = get_screen_sz(1);
		ft_putstr_fd(tgetstr("cl", NULL), 0);
		display_list(&e, ws, check_arg_size(&e, ws));
	}
}

static void		catch_tmp_signal(int sig)
{
	char	cmd[2];
	struct termios	t;

	if (sig == SIGTSTP)
	{
		if (tcgetattr(0, &t) == -1)
			exit(EXIT_FAILURE);
		cmd[0] = t.c_cc[VSUSP];
		cmd[1] = '\0';
		reset_term();
		ft_putstr_fd(tgetstr("ve", NULL), 0);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, cmd);
		if (tcsetattr(0, TCSADRAIN, &t) == -1)
			exit(EXIT_FAILURE);
	}
}

static void		catch_fg(int sig)
{
	struct termios	ex;
	struct winsize	ws;
	t_elem			*e;

	e = NULL;
	if (sig)
	{
		e = get_arg(NULL);
		ws = get_screen_sz(1);
		init_term(&ex);
		ft_putstr_fd(tgetstr("vi", NULL), 0);
		ft_putstr_fd(tgetstr("cl", NULL), 0);
		display_list(&e, ws, check_arg_size(&e, ws));
	}
}

void			sig(void)
{
	signal(SIGTSTP, catch_tmp_signal); // Ctrl-Z
	signal(SIGWINCH, catch_resize_signal); // Resize Screen
	signal(SIGCONT, catch_fg);
	signal(SIGINT, catch_exit_sig); // Ctrl-C
	signal(SIGHUP, catch_exit_sig);
	signal(SIGPIPE, catch_exit_sig);
	signal(SIGALRM, catch_exit_sig);
	signal(SIGTERM, catch_exit_sig);
	signal(SIGXCPU, catch_exit_sig);
	signal(SIGXFSZ, catch_exit_sig);
	signal(SIGVTALRM, catch_exit_sig);
	signal(SIGPROF, catch_exit_sig);
	signal(SIGUSR1, catch_exit_sig);
	signal(SIGUSR2, catch_exit_sig);
}
