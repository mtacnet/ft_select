/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:35:26 by mtacnet           #+#    #+#             */
/*   Updated: 2017/11/22 12:08:36 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <termios.h>
# include <term.h>
# include <curses.h>
# include <signal.h>
# include <sys/ioctl.h>

typedef struct		s_elem
{
	int				nb;
	int				arg_sz;
	int				hl;
	int				ul;
	char			*content;
	struct s_elem	*next;
}					t_elem;

/*
** LIST_FUNCTIONS
*/

t_elem				*new_list(void);
t_elem				*init_element(t_elem *element);
void				push_elemx(t_elem **lst, char *content, int nb, int arg_sz);
void				push_elem(t_elem **lst, char *content);
void				supp_elem(t_elem **lst, char *arg);
void				push_back(t_elem **lst, char *content);
void				view_list(t_elem **lst);
void				view_llist(t_elem **lst);
void				cpy_lst(t_elem **lst_dest, t_elem **lst_src);
void				freelst(t_elem **lst);
int					is_empty(t_elem **lst);

/*
** FONCTIONS ARRAY
*/

char				**list_to_tab(t_elem **lst);
void				tab_to_list(t_elem **lst, char **array);

#endif
