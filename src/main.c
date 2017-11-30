/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:52:07 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/30 16:49:55 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

/*
** get_term: Récupere la valeur de la variable d'environnement "TERM" et
** stock cette valeur dans le char* 'term'.
*/

static int		catch_term(char **term)
{
	if ((*term = getenv("TERM")) == NULL)
		return (-1);
	return (0);
}

int				main(int argc, char **argv)
{
	t_elem			*e;
	char			*term;

	e = new_list();
	term = NULL;
	sig();
	if (argc < 2)
		exit(EXIT_SUCCESS);
	else
	{
		if (catch_term(&term) != 0)
		{
			ft_putendl_fd("VARIABLE TERM IS NOT SET IN THE ENVIRONNEMENT", 2);
			exit(EXIT_FAILURE);
		}
		if (tgetent(NULL, term) == ERR)
			exit(EXIT_FAILURE);
		get_term(1);
		e = get_arg(argv);
		core(&e);
	}
	return (0);
}
