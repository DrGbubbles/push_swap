/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:18:36 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/01 22:11:24 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack->head || !stack->head->next)
		return ;
	first = stack->head;
	second = stack->head->next;
	first->next = second->next;
	second->next = first;
	stack->head = second;
}

void	sa(t_stack *stack, t_bench *bench)
{
	swap(stack);
	if (bench)
	{
		bench->sa++;
		bench->total++;
	}
	if (bench->show_ops)
		ft_printf("sa\n");
}

void	sb(t_stack *stack, t_bench *bench)
{
	swap(stack);
	if (bench)
	{
		bench->sb++;
		bench->total++;
	}
	if (bench->show_ops)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b, t_bench *bench)
{
	swap(a);
	swap(b);
	if (bench)
	{
		bench->ss++;
		bench->total++;
	}
	if (bench->show_ops)
		ft_printf("ss\n");
}
