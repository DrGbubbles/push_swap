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

void    merge_sort(t_stack *stack_a, t_stack *stack_b)
{
	//This algorithm sorts a list A pairwise, meaning that each block of 2 will be sorted.
	int		l;
	int		pos;
	int		n = ft_lstsize(stack_a->head);
	int		i;
	int		j;

	l = 1;
	pos = 0;
	while(l < n)
	{
		ft_printf("merging to a in pairs of %i\n ", 2 * l);
		if(l == 1)
			pair_sort(stack_a, stack_b);
		if (l > 1)
			return ;
		while (pos <= n - l && (l > 1))
		{
			i = 0;
			ft_printf("pushing %i to b:\n", l);
			while (i++ < ft_min(l, n - pos))
			{
				pb(stack_a, stack_b);
				rb(stack_b);
			}
			int stop = 0;
			i = 0;
			while (stack_b->head)
			{
				if (pos % ft_lstsize(stack_a->head) == 0 && *(int *)stack_b->head->content - *(int *)stack_a->tail->content > 0)
				{
					while(stack_b->head)
					{
						pa(stack_a, stack_b);
						ra(stack_a);
					}
					return ;
				}
				if ( *(int *)stack_a->head->content - *(int *)stack_b->head->content > 0 || i >= l)
					pa(stack_a, stack_b);
				pos++;
				ra(stack_a);
				i++;
			}
			while (i < 2 * l)
			{
				ra(stack_a);
				i++;
			}
			j = ft_lst_is_rot_sorted(stack_a);
			ft_printf("the list is rot sorted: %i \n", j);
			while(j > 0)
			{
					ra(stack_a);
					j--;
			}
			if (j == 0)
				return ;
		}
		pos = 0;
		l = 2 * l;
		print_stack("Stack A: ", stack_a);
		print_stack("Stack B: ", stack_b);
		if (ft_lst_is_sorted(stack_a->head))
		{
			ft_printf("List is sorted!\n");
			return ;
		}
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
