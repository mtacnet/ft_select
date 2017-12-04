/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:10:39 by mtacnet           #+#    #+#             */
/*   Updated: 2017/12/04 16:12:02 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int				check_display(t_elem **e, struct winsize ws, int nb_words)
{
	t_elem		*tmp;
	int			i;
	int			nb;

	tmp = (*e);
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->del == 0)
			i++;
		tmp = tmp->next;
	}
	nb = i / ws.ws_row;
	if (nb >= nb_words)
		return (1);
	else
		return (0);
}

static void		apply_termcap(t_elem *tmp)
{
	if (tmp->ul == 1)
		ft_putstr_fd(tgetstr("us", NULL), 0);
	if (tmp->hl == 1)
		ft_putstr_fd(tgetstr("mr", NULL), 0);
	ft_putstr_fd(tmp->content, 0);
	ft_putstr_fd(tgetstr("me", NULL), 0);
}

static void		apply_termcap2(t_elem *tmp, int nb_words, int arg_sz)
{
	int		i;
	int		k;

	i = 0;
	while (tmp != NULL)
	{
		if (tmp->del == 0)
		{
			apply_termcap(tmp);
			k = ft_strlenint(tmp->content) - 1;
			i++;
			if (i != nb_words)
				while (k++ < arg_sz)
					ft_putstr_fd(" ", 0);
			else
			{
				i = 0;
				ft_putstr_fd("\n", 0);
			}
		}
		tmp = tmp->next;
	}
}

void			display_list(t_elem **e, struct winsize ws, int arg_sz)
{
	t_elem		*tmp;
	int			nb_words;

	tmp = (*e);
	nb_words = 0;
	if (arg_sz != 0)
		nb_words = (ws.ws_col) / (arg_sz + 1);
	if (check_display(e, ws, nb_words) == 1)
		ft_putendl_fd("PLEASE RESIZE THE WINDOW TERM", 2);
	else
		apply_termcap2(tmp, nb_words, arg_sz);
}
