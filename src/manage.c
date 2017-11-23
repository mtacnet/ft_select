/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:32:42 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/22 15:04:02 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void		manage_key(char *buff, t_elem *tmp)
{
	if (buff[0] == 27 && buff[1] == 0 && buff[2] == 0 && buff[3] == 0)
		exit_term();
	if (buff[0] == 32)
	{
		tmp->ul = 0;
		tmp->hl = 1;
		if (tmp->next != NULL)
			tmp->next->ul = 1;
	}

}

int		manage(char *buff, t_elem **e, int pos)
{
	t_elem		*tmp;

	tmp = (*e);
	manage_key(buff, tmp);
	while (tmp != NULL && tmp->nb < pos)
		tmp = tmp->next;
	if (tmp != NULL)
	{
		manage_key(buff, tmp);
	}
	if (tmp->next != NULL)
		return (tmp->next->nb);
	else
		return (tmp->nb);
}
