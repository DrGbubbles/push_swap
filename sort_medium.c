/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 23:31:12 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/02 13:11:49 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(t_stack *stack_a)
{
	int		max;
	t_list	*tmp;

	max = *(int *)stack_a->head->content;
	tmp = stack_a->head;
	while (tmp)
	{
		if (*(int *)tmp->content > max)
			max = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

static int	get_chunks_num(t_stack *stack_a)
{
	int	i;
	int	lst_size;

	lst_size = ft_lstsize(stack_a->head);
	i = 0;
	while (i * i < lst_size)
		i++;
	return (i);
}

static void	push_chunk(t_stack *stack_a, t_stack *stack_b,
						int bounds[2], t_bench *bench)
{
	int	i;
	int	val;
	int	lst_size;

	lst_size = ft_lstsize(stack_a->head);
	i = 0;
	while (i < lst_size)
	{
		if (!stack_a->head)
			break ;
		val = *(int *)stack_a->head->content;
		if (val >= bounds[0] && val <= bounds[1])
			pb(stack_a, stack_b, bench);
		else
			ra(stack_a, bench);
		i++;
	}
}

static void	pull_back(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	int	size;
	int	max_pos;

	while (stack_b->head)
	{
		size = ft_lstsize(stack_b->head);
		max_pos = find_max_pos(stack_b->head, find_max(stack_b));
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(stack_b, bench);
		}
		else
		{
			while (max_pos < size)
			{
				rrb(stack_b, bench);
				max_pos++;
			}
		}
		pa(stack_a, stack_b, bench);
	}
}

void	bucket_sorting(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	int	i;
	int	chunks;
	int	chunk_sz;
	int	bounds[2];

	chunks = get_chunks_num(stack_a);
	bounds[0] = find_min(stack_a->head);
	chunk_sz = (find_max(stack_a) - bounds[0]) / chunks;
	i = 0;
	while (i < chunks)
	{
		bounds[1] = bounds[0] + chunk_sz;
		if (i == chunks - 1)
			bounds[1] = find_max(stack_a);
		push_chunk(stack_a, stack_b, bounds, bench);
		bounds[0] = bounds[1];
		i++;
	}
	pull_back(stack_a, stack_b, bench);
}
