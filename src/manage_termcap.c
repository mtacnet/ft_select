/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_termcap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:38:33 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/13 14:20:37 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void			move_cursor(int val)
{
	char	*res;

	res = NULL;
	if (val == 1)
		res = tgetstr("le", NULL);
	else if (val == 2)
		res = tgetstr("nd", NULL);
	else if (val == 3)
		res = tgetstr("up", NULL);
	else if (val == 4)
		res = tgetstr("do", NULL);
	else if (val == 5)
		res = tgetstr("us", NULL);
	if (res == NULL)
		exit(EXIT_FAILURE);
	else
		ft_putstr(res);
}
