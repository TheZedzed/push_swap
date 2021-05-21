#include "push_swap.h"

typedef struct s_sort
{
	int	lp;
	int	rp;
	int	size;
	t_list	*stack;
	t_list	*action;
}		t_sort;

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		partition(int *tab, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	i = -1;
	j = low - 1;
	pivot = tab[high];
	while (++i < high)
	{
		if (tab[i] <= pivot)
		{
			++j;
			swap(&tab[i], &tab[j]);
		}
	}
	swap(&tab[i + 1], &tab[high]);
	return (i + 1);
}

void	quicksort(int *tab, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(tab, low, high);
		quicksort(tab, low, pi - 1);
		quicksort(tab, pi + 1, high);
	}
}

void	sort(int *err, t_info *stacks, t_sort *param)
{
	while (!check_sort(stacks->stack_a) && stacks->stack_b)
	{
		param->stack = stacks->stack_a;
		set_pivot(err, param):
		
	}
}

void	set_pivot(int *err, t_sort *param)
{
	t_list	*curr;
	int	*tab;
	int	i;

	i = 0;
	tab = ft_calloc(param->size, sizeof(int));
	if (tab)
	{
		curr = param->stack;
		while (curr)
		{
			tab[i] = *(int *)curr->content;
			curr = curr->next;
			++i;
		}
		quicksort(tab, 0, size - 1);
		param->lp = tab[size / 3];
		param->rp = tab[(2 * size) / 3];
		free(tab);
	}
	else
		*err = 4;
}

int	main(int ac, char **av)
{
	t_sort	params;
	t_info	stacks;
	int		err;

	err = 0;
	ft_memset(&stacks, 0, sizeof(t_info));
	ft_memset(&params, 0, sizeof(t_sort));
	if (ac > 1)
	{
		parse_arg(&err, ++av, --ac, &stacks);
		if (!err)
		{
			if (!err && correct(&err, act))
			{
				sort(act, &stacks);
				if (stacks.stack_b || !check_sort(stacks.stack_a))
					printf("\033[31mKO\n\033[0m");
				else
					printf("\033[32mOK\n\033[0m");
			}
		}
	}
	return (print_error(err, &stacks, act));
}

