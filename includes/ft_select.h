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
void				manage(char *buff, t_elem **e);
void				exit_term(void);
void				move_cursor(int val);
int					check_arg_size(t_elem **e, struct winsize ws);
struct winsize		get_screen_sz(int val);
struct termios		get_term(int val);

#endif
