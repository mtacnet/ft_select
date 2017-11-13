/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:32:22 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/13 13:48:56 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/libft.h"
# include "./list.h"

/*
** MAIN_FUNCTIONS
*/

void				check_key();
void				core(struct termios *origin, t_elem **e);
void				term_mod(struct termios **origin);
void				man_termcap(int val, t_elem **e, struct termios **origin);
void				display_list(t_elem **e, int screen_sz, int arg_sz);
void				move_cursor(int val);
int					check_screen_size(void);

#endif
