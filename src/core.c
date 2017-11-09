/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:28:04 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/09 17:11:13 by mtacnet          ###   ########.fr       */
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
}

static void		clear_buff(char *buff)
{
	buff[0] = 0;
	buff[1] = 0;
	buff[2] = 0;
	buff[3] = 0;
}

static int		check_screen_size(void)
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

static void		check_arg_size(t_elem **e)
{
	int		i;
	int		total_length;
	t_elem	*head;

	i = 0;
	total_length = 0;
	head = (*e);
	while ((*e) != NULL)
	{
		if (ft_strlenint((*e)->content) > i)
			i = ft_strlenint((*e)->content);
		total_length = ft_strlenint((*e)->content) + total_length;
		if ((*e)->next != NULL)
			total_length += 1;
		(*e) = (*e)->next;
	}
	(*e) = head;
	ft_putnbr(i);
	ft_putchar('\n');
	ft_putnbr(total_length);
	ft_putchar('\n');
}

void			core(struct termios *origin, t_elem **e)
{
	char	buff[4];
	int		ret;

	term_mod(&origin);
	view_llist(e);
	ft_putchar('\n');
	while (1)
	{
		ret = check_screen_size();
		ft_putnbr(ret);
		ft_putchar('\n');
		check_arg_size(e);
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
			move_cursor(5); //espace
		else if (buff[0] == 27 && buff[1] == 0 && buff[2] == 0 && buff[3] == 0)
			man_termcap(0, e, &origin); //exit
		else if (buff[0] == 127)
			ft_putendl_fd("delete", 1);
		else if (buff[0] == 10 && buff[1] == 0 && buff[2] == 0 && buff[3] == 0)
			ft_putendl_fd("enter", 1);*/
	//	display_list(e);
	}
}
