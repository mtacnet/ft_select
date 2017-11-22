/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:14:44 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/22 13:29:35 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/list.h"

void	view_llist(t_elem **lst)
{
	t_elem		*head;

	head = (*lst);
	while ((*lst) != NULL)
	{
		ft_putstr((*lst)->content);
		if ((*lst)->next != NULL)
			ft_putstr(" ");
		(*lst) = (*lst)->next;
	}
	(*lst) = head;
}

void	view_list(t_elem **lst)
{
	t_elem		*head;

	head = (*lst);
	while ((*lst) != NULL)
	{
		ft_putstr("arg_size: ");
		ft_putnbr((*lst)->arg_sz);
		ft_putstr("  nb: ");
		ft_putnbr((*lst)->nb);
		ft_putchar('\n');
		ft_putendl((*lst)->content);
		(*lst) = (*lst)->next;
	}
	(*lst) = head;
}
