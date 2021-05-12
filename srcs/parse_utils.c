#include "push_swap.h"

int	is_numeric(char *str)
{
	while (*str)
	{
		if (!(*str >= 48 && *str <= 57))
			return (0);
		str++;
	}
	return (1);
}

int	over_flow(char *num, char *set)
{
	while (*num && *num == *set)
	{
		++num;
		++set;
	}
	if (*num && *num > *set)
		return (1);
	return (0);
}

char	**alloc(char **av, int ac)
{
	char	**res;
	int		j;

	j = -1;
	if (ac == 1)
		res = ft_split(av[0], ' ');
	else
	{
		res = ft_calloc(ac + 1, sizeof(char *));
		if (!res)
			return (NULL);
		while (++j < ac)
		{
			res[j] = ft_strdup(av[j]);
			if (!res[j])
			{
				free_alloc(res);
				return (NULL);
			}
		}
	}
	return (res);
}

int	is_valid(char *num, int len)
{
	static char	*under = "2147483648";
	static char	*over = "2147483647";
	char		*set;

	set = over;
	if (*num == '-')
	{
		set = under;
		++num;
	}
	if (!is_numeric(num) || (len >= 10 && over_flow(num, set)))
		return (0);
	return (1);
}

void	duplicate(int *err, t_list *stack)
{
	t_list	*curr;
	t_list	*next;

	curr = stack;
	while (!*err && curr)
	{
		next = curr->next;
		while (!*err && next)
		{
			if (*(int *)curr->content == *(int *)next->content)
				*err = 1;
			next = next->next;
		}
		curr = curr->next;
	}
}

