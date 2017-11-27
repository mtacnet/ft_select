#include "../includes/ft_select.h"

static void		select_elem(t_elem *tmp, t_elem **e, t_elem *prev)
{
	tmp->ul = 0;
	if (tmp->hl == 0)
		tmp->hl = 1;
	else
		tmp->hl = 0;
	move_cursor(1, tmp, prev, e);
}

void			move_cursor(int val, t_elem *tmp, t_elem *prev, t_elem **e)
{
	t_elem		*head;

	head = (*e);
	if (val == 1)
	{
		tmp->ul = 0;
		if (tmp->next != NULL)
			tmp = check_next(tmp->next);
		else
			tmp = head;
		tmp->ul = 1;
	}
	else if (val == 2)
	{
		tmp->ul = 0;
		prev->ul = 1;
	}
	else if (val == 3)
		select_elem(tmp, e, prev);
}
