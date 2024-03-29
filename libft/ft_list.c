/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:33:04 by mtacnet           #+#    #+#             */
/*   Updated: 2017/10/31 14:57:51 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/list.h"

void	push_elem(t_elem **lst, char *content)
{
	t_elem		*element;
	t_elem		*head;
	t_elem		*prev;

	element = NULL;
	element = init_element(element);
	element->content = ft_strdup(content);
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

void	supp_elem(t_elem **lst, char *arg)
{
	size_t		i;
	t_elem		*tmp;
	t_elem		*prev;

	i = 0;
	tmp = (*lst);
	prev = NULL;
	i = ft_strlen(arg);
	if (tmp != NULL && ft_strncmp(tmp->content, arg, i) == 0)
	{
		(*lst) = tmp->next;
		ft_strdel(&(tmp->content));
		free(tmp);
		return ;
	}
	while (tmp != NULL && ft_strncmp(tmp->content, arg, i) != 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	prev->next = tmp->next;
	ft_strdel(&(tmp->content));
	free(tmp);
}

void	push_back(t_elem **lst, char *content)
{
	t_elem		*element;
	t_elem		*tmp;

	element = NULL;
	element = init_element(element);
	element->content = ft_strdup(content);
	if (is_empty(lst))
	{
		(*lst) = element;
		return ;
	}
	tmp = (*lst);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
}

int		modif_list(t_elem **lst, char *arg)
{
	int			i;
	int			len;
	t_elem		*head;

	i = 0;
	len = 0;
	head = (*lst);
	while ((*lst) != NULL)
	{
		i = 0;
		while ((*lst)->content[i])
		{
			if ((*lst)->content[i] == '=')
				len = i;
			i++;
		}
		if (ft_strncmp((*lst)->content, arg, len) == 0)
		{
			(*lst) = head;
			return (1);
		}
		(*lst) = (*lst)->next;
	}
	(*lst) = head;
	return (0);
}
