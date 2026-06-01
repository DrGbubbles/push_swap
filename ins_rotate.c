/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:18:30 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/01 22:10:34 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->head || stack->head == stack->tail)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	stack->tail->next = tmp;
	tmp->next = NULL;
	stack->tail = tmp;
}

void	ra(t_stack *a, t_bench *bench)
{
	rotate(a);
	if (bench)
	{
		bench->ra++;
		bench->total++;
	}
	if (bench->show_ops)
		ft_printf("ra\n");
}

void	rb(t_stack *b, t_bench *bench)
{
	rotate(b);
	if (bench)
	{
		bench->rb++;
		bench->total++;
	}
	if (bench->show_ops)
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b, t_bench *bench)
{
	rotate(a);
	rotate(b);
	if (bench)
	{
		bench->rr++;
		bench->total++;
	}
	if (bench->show_ops)
		ft_printf("rr\n");
}
