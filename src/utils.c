/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:51:57 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/22 12:06:20 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

/*
** get_screen_sz: Si val == 1 alors initialiser la struct et la retourner
** si val == 0 alors retourner la struct deja remplie.
*/

struct winsize		get_screen_sz(int val)
{
	static struct winsize	w;

	if (val == 1)
	{
		if (ioctl(1, TIOCGWINSZ, &w) != 0)
		{
			ft_putendl_fd("WIDTH_RECOVER_IMPOSSIBLE", 2);
			exit(EXIT_FAILURE);
		}
	}
	return (w);
}

/*
** get_arg: Si la struct e == NULL alors elle est remplie avec les argv puis
** elle est retournée, sinon elle est retournée avec son contenu.
*/

t_elem				*get_arg(char **argv)
{
	static t_elem	*e = NULL;
	int				i;

	i = 1;
	if (!e)
	{
		if (argv != NULL)
		{
			while (argv[i] != '\0')
			{
				push_elemx(&e, argv[i], i, ft_strlenint(argv[i]));
				i++;
			}
		}
	}
	return (e);
}

/*
** init_term: Initialise le terminal avec les valeurs indiquées dans la fonction
*/

void			init_term(struct termios *term)
{
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		exit(EXIT_FAILURE);
}

/*
** get_term: Si val == 1 alors le terminal est récupéré - Sinon il est appliqué
** avant la fonction init_term().
*/

struct termios		get_term(int val)
{
	static struct termios	term;

	if (val == 1)
	{
		if (tcgetattr(0, &term) == -1)
			exit(EXIT_FAILURE);
	}
	else
		init_term(&term);
	return (term);
}

/*
** exit_term: Quitte le programme en restaurant les parametres par defaut du
** terminal et libere la mémoire alloué dynamiquement (liste t_elem).
*/

void				exit_term(void)
{
	t_elem		*term;

	term = get_arg(NULL);
	get_term(0);
	ft_putstr_fd(tgetstr("te", NULL), 0);
	ft_putstr_fd(tgetstr("ve", NULL), 0);
	freelst(&term);
	exit(EXIT_SUCCESS);
}
