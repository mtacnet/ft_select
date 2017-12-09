/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:51:04 by mtacnet           #+#    #+#             */
/*   Updated: 2017/12/09 12:11:20 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

/*
** inverse_all: Inverse la sélection des élements avec la touche "i" minuscule.
*/

static void		inverse_all(t_elem **e)
{
	t_elem		*tmp;

	tmp = (*e);
	while (tmp != NULL)
	{
		if (tmp->hl == 0)
			tmp->hl = 1;
		else
			tmp->hl = 0;
		tmp = tmp->next;
	}
}

/*
** select_all: Sélectionne tous les élements de la liste avec la touche "a"
*/

static void		select_all(t_elem **e)
{
	t_elem		*tmp;

	tmp = (*e);
	while (tmp != NULL)
	{
		if (tmp->hl == 0)
			tmp->hl = 1;
		tmp = tmp->next;
	}
}

/*
** deselect_all: Déselectionne tous les élements de la liste avec la touche "q"
*/

static void		deselect_all(t_elem **e)
{
	t_elem*tmp;

	tmp = (*e);
	while (tmp != NULL)
	{
		if (tmp->hl == 1)
			tmp->hl = 0;
		tmp = tmp->next;
	}
}

void			bonus(char *buff, t_elem **e)
{
	if (buff[0] == 105 && !(buff[1] + buff[2] + buff[3]))
		inverse_all(e);
	if (buff[0] == 97 && !(buff[1] + buff[2] + buff[3]))
		select_all(e);
	if (buff[0] == 113 && !(buff[1] + buff[2] + buff[3]))
		deselect_all(e);
}
