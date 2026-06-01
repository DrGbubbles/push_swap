/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:18:24 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/01 22:09:36 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_stack *stack)
{
	t_list	*current;
	t_list	*last;

	if (!stack->head || stack->head == stack->tail)
		return ;
	current = stack->head;
	while (current->next != stack->tail)
		current = current->next;
	last = stack->tail;
	last->next = stack->head;
	stack->head = last;
	current->next = NULL;
	stack->tail = current;
}

void	rra(t_stack *a, t_bench *bench)
{
	reverse(a);
	if (bench)
	{
		bench->rra++;
		bench->total++;
	}
	if (bench->show_ops)
		ft_printf("rra\n");
}

void	rrb(t_stack *b, t_bench *bench)
{
	reverse(b);
	if (bench)
	{
		bench->rrb++;
		bench->total++;
	}
	if (bench->show_ops)
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	reverse(a);
	reverse(b);
	if (bench)
	{
		bench->rrr++;
		bench->total++;
	}
	if (bench->show_ops)
		ft_printf("rrr\n");
}
