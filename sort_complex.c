#include "push_swap.h"

void    pair_sort(t_stack *stack_a, t_stack *stack_b)
{
	//This algorithm sorts a list A pairwise, meaning that each block of 2 will be sorted.
	int		l;
	int		pos;
	int		n = ft_lstsize(stack_a->head);

	pos = 0;
	while (pos < n)
	{
		if (pos < n - 1 && *(int *)stack_a->head->content > *(int *)stack_a->head->next->content)
			sa(stack_a);
		ra(stack_a);
		pos++;
		if (pos < n)
			ra(stack_a);
		pos++;
	}
}

int		ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	ft_push_n_stack(t_stack *stack_a, t_stack *stack_b, int n)
{
	while (n > 0)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
		n--;
	}
	return ;
}

void	ft_merge_stack(t_stack *stack_a, t_stack *stack_b, int n_a)
{
	while (stack_b->head)
	{
		if (n_a == 0 || (*(int *)stack_b->head->content < *(int *)stack_a->head->content))
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else
		{
			ra(stack_a);
			n_a--;
		}
	}
	while (n_a-- > 0)
		ra(stack_a);
	
}

void	merge_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		l;
	int		pos;
	int		n;

	l = 1;
	pos = 0;
	n = ft_lstsize(stack_a->head);
	while (l < n)
	{
		while (pos < n - l)
		{
			ft_printf("pushing %i elements to b", l);
			ft_push_n_stack(stack_a, stack_b, l);
			print_stack("Stack A: ", stack_a);
			print_stack("Stack B: ", stack_b);
			ft_printf("merging %i elements to a", l);
			ft_merge_stack(stack_a, stack_b, ft_min(l, n - pos - l));
			pos += l + ft_min(l, n - pos - l);
			print_stack("Stack A: ", stack_a);
			print_stack("Stack B: ", stack_b);
		}
		l = 2 * l;
		pos = 0;
	}
}

int    ft_lst_is_sorted(t_list *head)
{
	if (!head)
		return (0);
	while (head->next)
	{
		if (*(int *)head->content > *(int *)head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}


int    ft_lst_is_rot_sorted(t_stack *stack_a)
{
	int	i;
	int		stop = 0;
	t_list *head;
	int		i_out;

	head = stack_a->head;
	i = 0;
	if (!head)
		return (0);
	while (head->next)
	{
		if (*(int *)head->content > *(int *)head->next->content)
		{
			stop++;
			i_out = i;
		}
		head = head->next;
		i++;
	}
	if (stop == 0)
		return (0);
	//ft_printf("The stop condition is %i, the contents are tail: %i, tail %i \n", stop,*(int *)stack_a->tail->content , *(int *)stack_a->head->content);
	if (stop == 1 && (*(int *)stack_a->tail->content < *(int *)stack_a->head->content))
		return (i_out + 1);
	return (-1);
}

/*
run  shuf -i 0-99 -n 10 > args.txt
./push_swap $(cat args.txt) --complex
*/
