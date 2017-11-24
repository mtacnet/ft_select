/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:12:48 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/21 16:09:59 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/list.h"

t_elem		*new_list(void)
{
	return (NULL);
}

int			is_empty(t_elem **lst)
{
	if ((*lst) == NULL)
		return (1);
	else
		return (0);
}

t_elem		*init_element(t_elem *element)
{
	if (!(element = (t_elem*)malloc(sizeof(t_elem))))
	{
		ft_putendl("MEMORY ALLOCATION ERROR");
		exit(EXIT_FAILURE);
	}
	element->arg_sz = 0;
	element->hl = 0;
	element->ul = 0;
	element->del = 0;
	element->content = NULL;
	element->next = NULL;
	return (element);
}

void		freelst(t_elem **lst)
{
	t_elem		*list;
	t_elem		*tmp;

	list = (*lst);
	while (list)
	{
		tmp = list->next;
		ft_strdel(&(list->content));
		free(list);
		list = tmp;
	}
	(*lst) = NULL;
}
