/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:30:32 by mtacnet           #+#    #+#             */
/*   Updated: 2017/10/31 15:00:39 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/list.h"

char	**list_to_tab(t_elem **lst)
{
	int			i;
	size_t		j;
	char		**array;
	t_elem		*head;

	i = 0;
	j = 0;
	array = NULL;
	head = (*lst);
	while ((*lst) != NULL)
	{
		j++;
		(*lst) = (*lst)->next;
	}
	(*lst) = head;
	if (!(array = ft_memalloc(sizeof(*array) * (j + 1))))
		exit(EXIT_FAILURE);
	while ((*lst) != NULL)
	{
		array[i] = (*lst)->content;
		(*lst) = (*lst)->next;
		i++;
	}
	(*lst) = head;
	return (array);
}

void	tab_to_list(t_elem **lst, char **array)
{
	int		i;

	i = 0;
	while (array[i] && array[i][0] != '\0')
	{
		push_elem(lst, array[i]);
		i++;
	}
}

void	supp_elem_tab(char **array, int value)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (array[i] && array[i][0] != '\0')
		i++;
	if (value >= i)
		return ;
	else
	{
		while (j < i)
		{
			array[j] = array[j + 1];
			j++;
		}
	}
	return ;
}

void	free_tab(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		if (array[i] != NULL)
		{
			ft_strdel(&(array[i]));
			i++;
		}
		else
			i++;
	}
	free(array);
	array = NULL;
}
