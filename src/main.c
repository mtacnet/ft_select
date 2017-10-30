/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:52:06 by mtacnet           #+#    #+#             */
/*   Updated: 2017/10/30 13:21:33 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int		check_term(char **name_term)
{
	if ((*name_term = getenv("TERM")) == NULL)
		return (-1);
	return (0);
}

int				main(int argc, char **argv)
{
	t_elem		*e;
	char		*name_term;

	name_term = NULL;
	(void)argv;
	e = new_list();
	if (argc < 2)
		exit(EXIT_SUCCESS);
	else
	{
		if (check_term(&name_term) != 0)
			exit(EXIT_FAILURE);
		else
			ft_putendl(name_term);
	}
	return (0);
}
