/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:28:04 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/02 15:36:01 by mtacnet          ###   ########.fr       */
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

static void		clear_buffer(char *buffer)
{
	buffer[0] = 0;
	buffer[1] = 0;
	buffer[2] = 0;
	buffer[3] = 0;
}

void	core(struct termios *origin, t_elem **e)
{
	(void)e;
	char	buffer[4];

	term_mod(&origin);
	while (1)
	{
		clear_buffer(buffer);
		read(0, buffer, 3);
/*		ft_putnbr_fd(buffer[0], 1);
		ft_putnbr_fd(buffer[1], 1);
		ft_putnbr_fd(buffer[2], 1);
		ft_putnbr_fd(buffer[3], 1);*/
		if (buffer[2] == 68 )
			ft_putendl_fd("fleche gauche", 1);
		else if (buffer[2] == 67)
			ft_putendl_fd("fleche droite", 1);
		else if (buffer[2] == 65)
			ft_putendl_fd("fleche haut", 1);
		else if (buffer[2] == 66)
			ft_putendl_fd("fleche bas", 1);
		else if (buffer[0] == 32)
			ft_putendl_fd("space", 1);
	}
}
