/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:10:39 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/22 15:04:07 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	display_list(t_elem **e, struct winsize ws, int arg_sz)
{
	t_elem		*tmp;
	int			i;
	int			k;
	int			nb_words;

	tmp = (*e);
	nb_words = 0;
	if (arg_sz != 0)
		nb_words = ws.ws_col / arg_sz + 1;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->del == 0)
		{
			if (tmp->ul == 1)
				ft_putstr_fd(tgetstr("us", NULL), 1);
			if (tmp->hl == 1)
				ft_putstr_fd(tgetstr("mr", NULL), 1);
			ft_putstr_fd(tmp->content, 1);
			ft_putstr_fd(tgetstr("me", NULL), 1);
			k = ft_strlenint(tmp->content) - 1;
			i++;
			if (i != nb_words - 1)
			{
				while (k++ < arg_sz)
					ft_putstr_fd(" ", 1);
			}
			else
			{
				i = 0;
				ft_putstr_fd("\n", 1);
			}
		}
		tmp = tmp->next;
	}
}
