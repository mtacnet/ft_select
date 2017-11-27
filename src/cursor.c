#include "../includes/ft_select.h"

void	move_cursor(int val, t_elem *tmp, t_elem *prev, t_elem **e)
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
}
