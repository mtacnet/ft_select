/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_termcap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:38:33 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/13 14:20:37 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void		exit_term(t_elem **e, struct termios **origin)
{
	**origin = (*e)->term;
	if (tcsetattr(0, TCSANOW, *origin) == -1)
		exit(EXIT_FAILURE);
	else
	{
		ft_putstr_fd(tgetstr("ti", NULL), 0);
		ft_putstr_fd(tgetstr("vi", NULL), 0);
		exit(EXIT_SUCCESS);
	}
}

void			display_list(t_elem **e, int screen_sz, int arg_sz)
{
	int		i;
	int		k;
	int		j;
	int		l;

	i = 0;
	k = 0;
	j = 0;
	l = 0;
	while ((*e) != NULL)
	{
		k = k + ft_strlenint((*e)->content) + 1 + j;
		if ((*e)->next != NULL)
			l = ft_strlenint((*e)->next->content);
		if (k + l >= screen_sz)
		{
			ft_putstr_fd("\n", 1);
			k = 0;
		}
		ft_putstr_fd((*e)->content, 1);
		if ((*e)->next != NULL)
			ft_putstr_fd(" ", 1);
		if ((i = ft_strlenint((*e)->content)) < arg_sz)
		{
			j = 0;
			while (i < arg_sz)
			{
				ft_putstr_fd(" ", 1);
				i++;
				j++;
			}
		}
		(*e) = (*e)->next;
	}
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
	else if (val == 5)
		res = tgetstr("us", NULL);
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
