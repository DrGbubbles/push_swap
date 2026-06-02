/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbliard <gbliard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:17:09 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/02 14:44:44 by gbliard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_adaptive(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	int		disorder;
	int		len_list;

	disorder = ft_compute_disorder(stack_a);
	len_list = ft_lstsize(stack_a->head);
	if (len_list == 2)
		ft_two_sort(stack_a, bench);
	else if (len_list == 3)
		ft_three_sort(stack_a, bench);
	else if (len_list < 50 || disorder < 0.2 || disorder > 1 - 0.2)
		selection_sorting(stack_a, stack_b, bench);
	else if (len_list > 1000)
		merge_sort(stack_a, stack_b, bench);
	else
		bucket_sorting(stack_a, stack_b, bench);
}

int	ft_compute_disorder(t_stack *stack_a)
{
	int		mistakes;
	int		total_pairs;
	t_list	*ptr1;
	t_list	*ptr2;

	mistakes = 0;
	total_pairs = 0;
	ptr1 = stack_a->head;
	ptr2 = stack_a->head;
	if (ft_lstsize(ptr1) < 2)
		return (0);
	while (ptr1 != NULL)
	{
		ptr2 = ptr1->next;
		while (ptr2 != NULL)
		{
			total_pairs ++;
			if (*(int *)ptr1->content > *(int *)ptr2->content)
				mistakes ++;
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return (10000 * mistakes / total_pairs);
}

void	ft_two_sort(t_stack *stack_a, t_bench *bench)
{
	if (*(int *)stack_a->tail->content < *(int *)stack_a->head->content)
		sa(stack_a, bench);
	return ;
}

void	ft_three_sort(t_stack *stack_a, t_bench *bench)
{
	if (is_sorted(stack_a->head))
		return ;
	else if (ft_max_pos_1(stack_a) == 1)
		ra(stack_a, bench);
	else if (*(int *)stack_a->tail->content > *(int *)stack_a->head->content)
		sa(stack_a, bench);
	else
		rra(stack_a, bench);
	ft_three_sort(stack_a, bench);
	return ;
}

int	ft_max_pos_1(t_stack *stack_a)
{
	int		max;
	t_list	*head;

	head = stack_a->head;
	max = *(int *)head->content;
	while (head != NULL)
	{
		if (max < *(int *)head->content)
			return (0);
		head = head->next;
	}
	return (1);
}
