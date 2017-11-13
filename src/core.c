/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:28:04 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/13 13:48:56 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void			term_mod(struct termios **origin)
{
	(*origin)->c_lflag &= ~(ICANON);
	(*origin)->c_lflag &= ~(ECHO);
	(*origin)->c_cc[VMIN] = 1;
	(*origin)->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, *origin) == -1)
		exit(EXIT_FAILURE);
	ft_putstr_fd(tgetstr("ti", NULL), 0);
	ft_putstr_fd(tgetstr("vi", NULL), 0);
}

static void		clear_buff(char *buff)
{
	buff[0] = 0;
	buff[1] = 0;
	buff[2] = 0;
	buff[3] = 0;
}

int				check_screen_size(void)
{
	struct winsize	w;

	if (ioctl(1, TIOCGWINSZ, &w) != 0)
	{
		ft_putendl_fd("WIDTH_RECOVER_IMPOSSIBLE", 2);
		exit(EXIT_FAILURE);
	}
	else
		return (w.ws_col);
}

static int		check_arg_size(t_elem **e)
{
	int		i;
	int		k;
	t_elem	*head;

	i = 0;
	k = 0;
	head = (*e);
	while ((*e) != NULL)
	{
		if (ft_strlenint((*e)->content) > i)
			i = ft_strlenint((*e)->content);
		if ((*e)->next != NULL)
			k++;
		(*e) = (*e)->next;
	}
	(*e) = head;
	return (i);
}

void			core(struct termios *origin, t_elem **e)
{
	char	buff[4];
	int		ret;
	int		ret2;

	term_mod(&origin);
	while (1)
	{
		ret = check_screen_size();
		ret2 = check_arg_size(e);
		display_list(e, ret, ret2);
		clear_buff(buff);
		read(0, buff, 3);
	/*	if (buff[2] == 68)
			move_cursor(1);
		else if (buff[2] == 67)
			move_cursor(2);
		else if (buff[2] == 65)
			move_cursor(3);
		else if (buff[2] == 66)
			move_cursor(4);
		else if (buff[0] == 32)
			move_cursor(5); //espace*/
		if (buff[0] == 27 && buff[1] == 0 && buff[2] == 0 && buff[3] == 0)
			man_termcap(0, e, &origin); //exit
		 if (buff[0] == 127)
			ft_putendl_fd("delete", 1);
		if (buff[0] == 10 && buff[1] == 0 && buff[2] == 0 && buff[3] == 0)
			ft_putendl_fd("enter", 1);
	}
}
