#include "../includes/ft_select.h"

t_elem	*check_next(t_elem *tmp)
{
	t_elem		*next;

	next = NULL;
	if (tmp)
	{
		next = tmp;
		while (next->next != NULL && next->del == 1)
			next = next->next;
	}
	return (next);
}

static void		manage_key(char *buff, t_elem *tmp, t_elem *prev, t_elem **e)
{
	if (buff[0] == 27 && buff[1] == 0 && buff[2] == 0 && buff[3] == 0)
		exit_term();
	else if (buff[2] == 67)
		move_cursor(1, tmp, prev, e);
	else if (buff[2] == 68)
		move_cursor(2, tmp, prev, e);
}

static t_elem	*check_prev(t_elem *tmp, t_elem **e)
{
	t_elem		*prev;

	prev = (*e);
	if (tmp)
	{
		if ((tmp->nb - 1) < 1)
			prev = last_elem(e);
		else
			while (prev->nb < (tmp->nb - 1) && prev->del == 0)
				prev = prev->next;
	}
	return (prev);
}

static int		return_pos(t_elem **e)
{
	int			i;
	t_elem		*tmp;

	i = 1;
	tmp = (*e);
	while (tmp->next != NULL && tmp->ul != 1)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		manage(char *buff, t_elem **e, int pos)
{
	t_elem		*tmp;
	t_elem		*prev;
	int			i;

	i = 0;
	prev = NULL;
	tmp = (*e);
	while (tmp && tmp->nb < pos)
	{
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
	if (tmp != NULL)
	{
		prev = check_prev(tmp, e);
		manage_key(buff, tmp, prev, e);
	}
	i = return_pos(e);
	return (i);
}
