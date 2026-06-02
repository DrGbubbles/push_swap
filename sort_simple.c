/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 22:11:12 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/02 23:28:25 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (!lst)
		return (1);
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	find_min(t_list *lst)
{
	int		min;
	t_list	*tmp;

	min = *(int *)lst->content;
	tmp = lst;
	while (tmp)
	{
		if (*(int *)tmp->content < min)
			min = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

static int	find_min_pos(t_list *lst, int min_num)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		if (*(int *)tmp->content == min_num)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

static void	bring_min_to_top(t_stack *stack_a, t_bench *bench,
				int min, int size)
{
	int	min_pos;

	min_pos = find_min_pos(stack_a->head, min);
	if (min_pos > size / 2)
		rra(stack_a, bench);
	else
		ra(stack_a, bench);
}

void	selection_sorting(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	int	current_min;
	int	size;

	if (is_sorted(stack_a->head))
		return ;
	size = ft_lstsize(stack_a->head);
	current_min = find_min(stack_a->head);
	while (size > 0)
	{
		if (*(int *)stack_a->head->content == current_min)
		{
			pb(stack_a, stack_b, bench);
			if (stack_a->head)
				current_min = find_min(stack_a->head);
			size--;
		}
		else
			bring_min_to_top(stack_a, bench, current_min, size);
	}
	while (stack_b->head)
		pa(stack_a, stack_b, bench);
}
