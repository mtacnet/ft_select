/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:33:04 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/22 12:06:50 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/list.h"

static void		add_element(t_elem **element, char *arg, int nb, int arg_sz)
{
	(*element)->content = ft_strdup(arg);
	(*element)->nb = nb;
	(*element)->arg_sz = arg_sz;
}

void	push_elemx(t_elem **lst, char *content, int nb, int content_sz)
{
	t_elem		*element;
	t_elem		*head;
	t_elem		*prev;

	element = NULL;
	element = init_element(element);
	add_element(&element, content, nb, content_sz);
	head = (*lst);
	prev = NULL;
	if (is_empty(lst))
	{
		(*lst) = element;
		return ;
	}
	while ((*lst) != NULL)
	{
		prev = (*lst);
		(*lst) = (*lst)->next;
	}
	if (prev)
		prev->next = element;
	else
		head = element;
	element->next = (*lst);
	(*lst) = head;
}
