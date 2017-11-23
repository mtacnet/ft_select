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

int		manage(char *buff, t_elem **e, int pos)
{
	t_elem		*tmp;
	tmp = (*e);
	while (tmp != NULL && tmp->nb < pos)
		tmp = tmp->next;
	if (tmp != NULL)
	{
		if (buff[0] == 32)
		{
			tmp->ul = 0;
			tmp->hl = 1;
			if (tmp->next != NULL)
				tmp->next->ul = 1;
		}
	}
	if (tmp->next != NULL)
		return (tmp->next->nb);
	else
		return (tmp->nb);
}
