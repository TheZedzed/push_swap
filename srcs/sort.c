#include "push_swap.h"

void	sort(t_list *act, t_info *ps)
{
	char	*ope;

	while (act)
	{
		ope = (char *)act->content;
		if (*ope == 'r' && ft_strlen(ope) == 3)
			rr_func(ope, ps);
		else if (*ope == 'r' && ft_strlen(ope) == 2)
			r_func(ope, ps);
		else if (*ope == 's')
			s_func(ope, ps);
		else
			p_func(ope, ps);
		print_list(ps, ope);
		act = act->next;
	}
}

void	s_func(char *ope, t_info *ps)
{
	if (ope[1] == 'a')
		swap_front(&ps->stack_a);
	else if (ope[1] == 'b')
		swap_front(&ps->stack_b);
	else
	{
		swap_front(&ps->stack_a);
		swap_front(&ps->stack_b);
	}
}

void	p_func(char *ope, t_info *ps)
{
	if (ope[1] == 'b')
	{
		if (!ps->size_a)
			return ;
		ps->size_b += 1;
		ps->size_a -= 1;
		push_front(&ps->stack_b, &ps->stack_a);
	}
	else
	{
		if (!ps->size_b)
			return ;
		ps->size_a += 1;
		ps->size_b -= 1;
		push_front(&ps->stack_a, &ps->stack_b);
	}
}

void	r_func(char *ope, t_info *ps)
{
	if (ope[1] == 'a')
	{
		rotate_front(&ps->stack_a);
	}
	else if (ope[1] == 'b')
	{
		rotate_front(&ps->stack_b);	
	}
	else
	{
		rotate_front(&ps->stack_a);
		rotate_front(&ps->stack_b);
	}
}

void	rr_func(char *ope, t_info *ps)
{
	if (ope[2] == 'a')
	{
		rrotate_front(&ps->stack_a);
	}
	else if (ope[2] == 'b')
	{
		rrotate_front(&ps->stack_b);	
	}
	else
	{
		rrotate_front(&ps->stack_a);
		rrotate_front(&ps->stack_b);
	}
}

