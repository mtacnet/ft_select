/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:51:50 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/22 15:04:08 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int				check_arg_size(t_elem **e, struct winsize ws)
{
	int		i;
	t_elem	*head;

	i = 0;
	head = (*e);
	while ((*e) != NULL)
	{
		if (ft_strlenint((*e)->content) > i)
			i = ft_strlenint((*e)->content);
		(*e) = (*e)->next;
	}
	(*e) = head;
	if (i > ws.ws_col)
		return (-1);
	else
		return (i);
}

static void		clear_buff(char *buff)
{
	buff[0] = 0;
	buff[1] = 0;
	buff[2] = 0;
	buff[3] = 0;
}

void		empty_list(t_elem **e)
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
		exit_term();
}

void			core(t_elem **e)
{
	char			buff[4];
	struct winsize	ws;
	int				arg_sz;
	int				pos;

	pos = 1;
	ws = get_screen_sz(1);
	if ((arg_sz = check_arg_size(e, ws)) == -1)
		ft_putendl_fd("PLEASE RESIZE SCREEN", 2);
	get_term(0);
	ft_putstr_fd(tgetstr("ti", NULL), 0);
	ft_putstr_fd(tgetstr("vi", NULL), 0);
	(*e)->ul = 1;
	while (1)
	{
		display_list(e, get_screen_sz(0), arg_sz);
		clear_buff(buff);
		read(0, buff, 3);
		ft_putstr_fd(tgetstr("cl", NULL), 0);
		pos = manage(buff, e, pos);
	}
}
