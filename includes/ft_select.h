/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:32:22 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/22 15:04:03 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/libft.h"
# include "./list.h"

/*
** MAIN_FUNCTIONS
*/

t_elem				*get_arg(char **argv);
void				core(t_elem **e);
void				sig(void);
void				display_list(t_elem **e, struct winsize ws, int arg_sz);
void				manage_termcap(char *buff, char *arg, int nb);
void				exit_term(void);
void				move_cursor(int val, t_elem *tmp, t_elem *prev, t_elem **e);
int					check_arg_size(t_elem **e, struct winsize ws);
int					manage(char *buff, t_elem **e, int pos);
struct winsize		get_screen_sz(int val);
struct termios		get_term(int val);
t_elem				*check_next(t_elem *tmp);
t_elem				*check_prev(t_elem *tmp, t_elem **e);
t_elem				*last_elem(t_elem **e);

#endif
