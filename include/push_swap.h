#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

typedef struct s_info
{
	int	size_a;
	int	size_b;
	t_list	*stack_a;
	t_list	*stack_b;
}		t_info;

char	**alloc(char **av, int ac);
int	check_sort(t_list *stack);
void	sort(t_list *act, t_info *ps);
int	correct(int *err, t_list *act);

int	is_valid(char *num, int len);
int	is_numeric(char *num);
int	over_flow(char *num, char *set);
int	tab_size(char **tab);

void	get_action(int *err, int fd, t_list **act);
void	duplicate(int *err, t_list *stack);
void	push_back(int *err, char *nb, t_info *ps);
void	parse_arg(int *err, char **av, int ac, t_info *ps);

void	p_func(char *ope, t_info *ps);
void	push_front(t_list **dst, t_list **src);
void	swap_front(t_list **stack);
void	s_func(char *ope, t_info *ps);
void	rotate_front(t_list **src);
void	r_func(char *ope, t_info *ps);
void	rrotate_front(t_list **src);
void	rr_func(char *ope, t_info *ps);

void	free_list(t_list *head);
void	free_alloc(char **tab);
int	print_error(int err, t_info *ps, t_list *c);
void	print_list(t_info *ps, char *ope);

#endif
