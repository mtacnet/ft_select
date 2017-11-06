/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:28:04 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/06 14:37:19 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	term_mod(struct termios **origin)
{
	(*origin)->c_lflag &= ~ (ICANON);
	(*origin)->c_lflag &= ~ (ECHO);
	(*origin)->c_cc[VMIN] = 1;
	(*origin)->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, *origin) == -1)
		exit(EXIT_FAILURE);
}

static void		clear_buff(char *buff)
{
	buff[0] = 0;
	buff[1] = 0;
	buff[2] = 0;
	buff[3] = 0;
}

void	core(struct termios *origin, t_elem **e)
{
	char	buff[4];

	term_mod(&origin);
	while (1)
	{
		clear_buff(buff);
		read(0, buff, 3);
		if (buff[2] == 68 )
		{
			ft_putendl_fd("fleche gauche", 1);
		}
		else if (buff[2] == 67)
		{
			ft_putendl_fd("fleche droite", 1);
		}
		else if (buff[2] == 65)
		{
			ft_putendl_fd("fleche haut", 1);
		}
		else if (buff[2] == 66)
		{
			ft_putendl_fd("fleche bas", 1);
		}
		else if (buff[0] == 32)
		{
			ft_putendl_fd("space", 1);
		}
		else if (buff[0] == 27 && buff[1] == 0 && buff[2] == 0 && buff[3] == 0)
			man_termcap(0, e, &origin);
		else if (buff[0] == 127)
		{
			ft_putendl_fd("delete", 1);
		}
		else if (buff[0] == 10 && buff[1] == 0 && buff[2] == 0 && buff[3] == 0)
		{
			ft_putendl_fd("enter", 1);
		}
		//display_list(e);
	}
}
