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

void	manage(char *buff, t_elem **e)
{
	t_elem		*tmp;
	int			i;

	tmp = (*e);
	i = 1;
	while (tmp != NULL)
	{
		if (buff[0] == 32)
		{
			tmp->ul = 0;
			if (tmp->hl == 0)
			{
				tmp->hl = 1;
				tmp->next->ul = 1;
			}
			else
				tmp->hl = 0;
		}
		i++;
		return ;
		tmp = tmp->next;
	}
}
