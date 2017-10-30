/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:52:06 by mtacnet           #+#    #+#             */
/*   Updated: 2017/10/30 13:53:42 by mtacnet          ###   ########.fr       */
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
	struct termios	term;
	char			*name_term;
	(void)argv;

	name_term = NULL;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	else
	{
		if (check_term(&name_term) != 0)
			exit(EXIT_FAILURE);
		if (tgetent(NULL, name_term) == ERR)
			return (EXIT_FAILURE);
		if (tcgetattr(0, &term) == -1)
			exit(EXIT_FAILURE);
		else
			ft_putendl(name_term);
	}
	return (0);
}
