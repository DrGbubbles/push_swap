/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 22:11:12 by ktaher            #+#    #+#             */
/*   Updated: 2026/05/26 18:58:24 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	find_min(t_list *lst)
{
	t_list *tmp;
	int	min;

	min = INT_MAX;
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
	t_list *tmp;
	int i;

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

void	selection_sorting(t_stack *stack_a, t_stack *stack_b)
{
	int	current_min;
	int	i;
	int	lst_size;
	int	min_pos;

	i = 0;
	lst_size = ft_lstsize(stack_a->head);
	current_min = find_min(stack_a->head);
	while (i != lst_size)
	{
		if (*(int *)stack_a->head->content == current_min)
		{
			pb(stack_a, stack_b);
			current_min = find_min(stack_a->head);
			i++;
		}
		else
		{
			min_pos = find_min_pos(stack_a->head, current_min);
			if (min_pos > ft_lstsize(stack_a->head) / 2)
				rra(stack_a);
			else
				ra(stack_a);
		}
	}
	while(stack_b->head)
		pa(stack_a, stack_b);
}



