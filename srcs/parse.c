#include "push_swap.h"

void	parse_arg(int *err, char **av, int ac, t_info *ps)
{
	char	**tab;
	int		len;
	int		i;

	i = -1;
	tab = alloc(av, ac);
	len = tab_size(tab);
	if (tab)
	{
		while (!*err && ++i < len)
			push_back(err, tab[i], ps);
		duplicate(err, ps->stack_a);
		free_alloc(tab);
	}
}

void	get_action(int *err, int fd, t_list **head)
{
	t_list	*new;
	char	*line;
	int	res;

	res = 1;
	//fd = open("test", O_RDONLY);
	while (!*err && res > 0)
	{
		res = get_next_line(fd, &line);
		if (res < 0)
			*err = 5;
		if (*line)
		{
			new = ft_lstnew(ft_strdup(line));
			if (!new || !new->content)
				*err = 6;
			else
				ft_lstadd_back(head, new);
		}
		free(line);
	}
}

int	correct(int *err, t_list *act)
{
	static char	*s1[7] = {"rr", "ra", "rb", "sa", "sb", "ss", 0};
	static char	*s2[7] = {"rrr", "rra", "rrb", "pa", "pb", 0, 0};
	int			i;

	while (!*err && act)
	{
		i = 0;
		while (s1[i] || s2[i])
		{
			if (s1[i] && !ft_strcmp(s1[i], (char *)act->content))
				break ;
			if (s2[i] && !ft_strcmp(s2[i], (char *)act->content))
				break ;
			++i;
		}
		if (!s1[i] && !s2[i])
			*err = 1;
		act = act->next;
	}
	return (!*err);
}

void	push_back(int *err, char *nb, t_info *ps)
{
	t_list	*new;
	int		len;

	len = ft_strlen(nb);
	if (len <= 11 && is_valid(nb, len))
	{
		new = ft_lstnew(ft_calloc(1, sizeof(int)));
		if (!new || !new->content)
			*err = 4;
		else
		{
			ps->size_a += 1;
			*(int *)new->content = ft_atoi(nb);
			ft_lstadd_back(&ps->stack_a, new);
		}
	}
	else
		*err = 3;
}

int	tab_size(char **tab)
{
	int	len;

	len = 0;
	while (*tab++)
		++len;
	return (len);
}
