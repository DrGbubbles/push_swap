/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 23:31:12 by ktaher            #+#    #+#             */
/*   Updated: 2026/05/31 22:04:29 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_pos(t_list *lst, int max_num)
{
	t_list				*tmp;
	int					i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		if (*(int *)tmp->content == max_num)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

static	int find_max(t_stack *stack_a)
{
	int	max;
	t_list *tmp;
	
	max = *(int *)stack_a->head->content;
	tmp = stack_a->head;
	while (tmp)
	{
		if (*(int *)tmp->content > max)
		{
			max = *(int *)tmp->content;
		}
		tmp = tmp->next;
	}
	return (max);
}

static	int get_chunks_num(t_stack *stack_a)
{
	int	i;
	int	lst_size;

	lst_size = ft_lstsize(stack_a->head);
	i = 0;
	while (i * i < lst_size)
		i++;
	return (i);
}

static void push_chunk(t_stack *stack_a, t_stack *stack_b,
						int lower, int upper)
{
	int i;
	int val;
	int	lst_size;

	lst_size = ft_lstsize(stack_a->head);
	i = 0;
	while (i < lst_size)
	{
		if (!stack_a->head)
			break ;
		val = *(int *)stack_a->head->content;
		if (val >= lower && val <= upper)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

static void pull_back(t_stack *stack_a, t_stack *stack_b)
{
	int size;
	int max_pos;
	int max;

	while (stack_b->head)
	{
		max = find_max(stack_b);
		size = ft_lstsize(stack_b->head);
		max_pos = find_max_pos(stack_b->head, max);
		
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(stack_b);
		}
		else
		{
			while (max_pos < size)
			{
				rrb(stack_b);
				max_pos++;
			}
		}
		pa(stack_a, stack_b);
	}
}

void	bucket_sorting(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	max;
	int	num_of_chunks;
	int	i;
	int chunk_size;
	
	i = 0;
	min = find_min(stack_a->head);
	max = find_max(stack_a);
	num_of_chunks = get_chunks_num(stack_a);
	chunk_size = (max - min) / num_of_chunks;
	while (i < num_of_chunks)
	{
		int lower = min + i * chunk_size;
		int upper = (i == num_of_chunks - 1) ? max : min + (i + 1) * chunk_size;
		push_chunk(stack_a, stack_b, lower, upper);
		i++;
	}
	pull_back(stack_a, stack_b);
}
