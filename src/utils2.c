#include "../includes/ft_select.h"

t_elem		*check_prev(t_elem *tmp, t_elem **e)
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

t_elem		*check_next(t_elem *tmp)
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

t_elem		*last_elem(t_elem **e)
{
	t_elem		*tmp;
	tmp = (*e);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

