#include "../includes/ft_select.h"

void				exit_term(void)
{
	struct termios t;
	
	if (tcgetattr(0, &t) == -1)
		exit(EXIT_FAILURE);
	t.c_lflag &= ~(ICANON);
	t.c_lflag &= ~(ECHO);
	t.c_cc[VMIN] = 1;
	t.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &t) == -1)
		exit(EXIT_FAILURE);
	ft_putstr_fd(tgetstr("te", NULL), 0);
	ft_putstr_fd(tgetstr("ve", NULL), 0);
	exit(EXIT_SUCCESS);
}

void				display_list1(t_elem **e)
{
	t_elem		*head;

	head = (*e);
	while ((*e) != NULL)
	{
		ft_putendl_fd((*e)->content, 1);
		(*e) = (*e)->next;
	}
	(*e) = head;
}

void				display_list(t_elem **e, struct winsize w, int arg_sz)
{
	t_elem	*head;
	int		i;
	int		k;
	int		nb_word;
	
	head = (*e);
	nb_word = w.ws_col / arg_sz + 1;
	i = 0;
	while ((*e) != NULL)
	{
		ft_putstr_fd((*e)->content, 1);
		k = ft_strlenint((*e)->content);
		i++;
		if (i != nb_word - 1)
		{
			while (k < arg_sz)
			{
				ft_putstr_fd(" ", 1);
				k++;
			}
		}
		else
		{
			i = 0;
			ft_putstr_fd("\n", 1);
		}
		(*e) = (*e)->next;
	}
}

struct winsize		check_screen_size(void)
{
	struct winsize	w;

	if (ioctl(1, TIOCGWINSZ, &w) != 0)
	{
		ft_putendl_fd("WIDTH_R	ECOVER_IMPOSSIBLE", 2);
		exit(EXIT_FAILURE);
	}
	else
		return (w);
}
