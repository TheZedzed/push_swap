#include "push_swap.h"

void	swap_front(t_list **a)
{
	t_list	*curr;
	void	*tmp;

	curr = *a;
	if (curr && curr->next)
	{
		tmp = curr->next->content;
		curr->next->content = curr->content;
		curr->content = tmp;
	}
}

void	push_front(t_list **dst, t_list **src)
{
	t_list	*curr;

	curr = (*src);
	(*src) = (*src)->next;
	curr->next = NULL;
	ft_lstadd_front(dst, curr);
}

void	rotate_front(t_list **a)
{
	t_list	*head;
	t_list	*last;

	if (*a && (*a)->next)
	{
		head = (*a);
		last = ft_lstlast(head);
		(*a) = (*a)->next;
		last->next = head;
		head->next = NULL;
	}
}

void	rrotate_front(t_list **a)
{
	t_list	*head;
	t_list	*last;
	t_list	*tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a);
		head = tmp;
		last = ft_lstlast(*a);
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next = NULL;
		(*a) = last;
		(*a)->next = head;
	}
}

