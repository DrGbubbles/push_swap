/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:18:19 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/01 23:43:00 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *stack_A, t_stack *stack_B)
{
	t_list	*node;

	if (!stack_A->head)
		return ;
	node = stack_A->head;
	stack_A->head = node->next;
	if (!stack_A->head)
		stack_A->tail = NULL;
	node->next = stack_B->head;
	stack_B->head = node;
	if (!stack_B->tail)
		stack_B->tail = node;
}

void	pb(t_stack *a, t_stack *b, t_bench *bench)
{
	push(a, b);
	if (bench)
	{
		bench->pb++;
		bench->total++;
	}
	if (bench->show_ops)
		ft_printf("pb\n");
}

void	pa(t_stack *a, t_stack *b, t_bench *bench)
{
	push(b, a);
	if (bench)
	{
		bench->pa++;
		bench->total++;
	}
	if (bench->show_ops)
		ft_printf("pa\n");
}
