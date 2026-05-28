/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 22:11:12 by ktaher            #+#    #+#             */
/*   Updated: 2026/05/28 23:12:03 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	find_min(t_list *lst)
{
	int						min;
	t_list					*tmp;

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
	t_list				*tmp;
	int					i;

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

void    selection_sorting(t_stack *stack_a, t_stack *stack_b)
{
	int	current_min;
	int	i;
	int	original_size;
	int	current_size;
	int	min_pos;

	if (is_sorted(stack_a->head))
		return ;

	i = 0;
	original_size = ft_lstsize(stack_a->head);
	current_size = original_size;
	current_min = find_min(stack_a->head);
	while (i < original_size)
	{
		if (*(int *)stack_a->head->content == current_min)
		{
			pb(stack_a, stack_b);
			if (stack_a->head)
				current_min = find_min(stack_a->head);
			i++;
			current_size--;
		}
		else
		{
			min_pos = find_min_pos(stack_a->head, current_min);
			if (min_pos > current_size / 2)
				rra(stack_a);
			else
				ra(stack_a);
		}
	}
	while (stack_b->head)
		pa(stack_a, stack_b);
}
