/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:51:50 by mtacnet           #+#    #+#             */
/*   Updated: 2017/12/04 14:06:00 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int				check_arg_size(t_elem **e)
{
	int		i;
	t_elem	*head;

	i = 0;
	head = (*e);
	while ((*e) != NULL)
	{
		if ((*e)->del == 0 && ft_strlenint((*e)->content) > i)
			i = ft_strlenint((*e)->content);
		(*e) = (*e)->next;
	}
	(*e) = head;
	return (i);
}

static void		clear_buff(char *buff)
{
	buff[0] = 0;
	buff[1] = 0;
	buff[2] = 0;
	buff[3] = 0;
}

void			empty_list(t_elem **e)
{
	t_elem		*tmp;
	int			i;

	i = 0;
	tmp = (*e);
	while (tmp != NULL)
	{
		if (tmp->del == 0)
			i++;
		tmp = tmp->next;
	}
	if (i == 0)
		exit_term(1);
}

void			core(t_elem **e)
{
	char			buff[4];
	struct winsize	ws;
	int				arg_sz;
	int				pos;

	pos = 1;
	ws = get_screen_sz(1);
	arg_sz = check_arg_size(e);
	get_term(2);
	ft_putstr_fd(tgetstr("ti", NULL), 0);
	ft_putstr_fd(tgetstr("vi", NULL), 0);
	(*e)->ul = 1;
	while (1)
	{
		display_list(e, get_screen_sz(0), check_arg_size(e));
		clear_buff(buff);
		read(0, buff, 3);
		ft_putstr_fd(tgetstr("cl", NULL), 0);
		pos = manage(buff, e, pos);
		if (buff[0] == 10 && buff[1] == 0 && buff[2] == 0 && buff[3] == 0)
			display_elem(e);
	}
}
