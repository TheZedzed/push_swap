#include "push_swap.h"

int	check_sort(t_list *stack1)
{
	while (stack1 && stack1->next)
	{
		if (*(int *)stack1->content > *(int *)stack1->next->content)
			return (0);
		stack1 = stack1->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_info	stacks;
	t_list	*act;
	int		err;
	int		fd;

	fd = 0;
	err = 0;
	act = NULL;
	ft_memset(&stacks, 0, sizeof(t_info));
	if (ac > 1)
	{
		parse_arg(&err, ++av, --ac, &stacks);
		if (!err)
		{
			get_action(&err, fd, &act);
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
