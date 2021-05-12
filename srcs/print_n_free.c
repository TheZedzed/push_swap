#include "push_swap.h"

int	print_error(int err, t_info *ps, t_list *c)
{
	if (err)
		write(2, "Error\n", 6);
	free_list(ps->stack_a);
	free_list(ps->stack_b);
	free_list(c);
	return (0);
}

void print_list(t_info	*ps, char *ope)
{
	t_list	*curr1;
	t_list	*curr2;
	int	size_a;
	int	size_b;

	size_a = ps->size_a;
	size_b = ps->size_b;
	curr1 = ps->stack_a;
	curr2 = ps->stack_b;
	printf("\nExec: %s\n", ope);
	while (size_a || size_b)
	{
		if (size_a && size_a >= size_b)
		{
			printf("%d", *(int *)curr1->content);
			curr1 = curr1->next;
			--size_a;
		}
		if (size_b && size_b >= size_a + 1)
		{
			printf("\t\t%d", *(int *)curr2->content);
			curr2 = curr2->next;
			--size_b;
		}
		printf("\n");
	}
	printf("-----------------\na\t\tb\n");
}

void	free_list(t_list *head)
{
	t_list	*curr;
	t_list	*next;

	curr = head;
	while (curr)
	{
		next = curr->next;
		free(curr->content);
		free(curr);
		curr = next;
	}
}

void	free_alloc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
	tab = NULL;
}
