/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:52:06 by mtacnet           #+#    #+#             */
/*   Updated: 2017/10/31 14:34:23 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int		check_term(char **name_term)
{
	if ((*name_term = getenv("TERM")) == NULL)
		return (-1);
	return (0);
}

static void		save_arg(t_elem **e, char **argv)
{
	int		i;

	i = 1;
	while (argv[i] != '\0')
	{
		push_elem(e, argv[i]);
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_elem			*e;
	struct termios	term;
	char			*name_term;

	e = new_list();
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
		save_arg(&e, argv);
//		save_term(&term
//		view_list(&e);
//		core(&term, &e);
	}
	return (0);
}
