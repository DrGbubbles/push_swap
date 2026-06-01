/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:33:45 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/01 21:53:24 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double calc_disorder(t_stack *stack_a)
{
	double mistakes;
	double total_pairs;
	t_list *tmp;
	t_list	*tmp_outer;

	mistakes = 0;
	total_pairs = 0;
	if (is_sorted(stack_a->head))
		return (0);
	tmp_outer = stack_a->head;
	while (tmp_outer)
	{
		tmp = tmp_outer->next;
		while(tmp)
		{
			total_pairs+=1;
			if (*(int *)tmp_outer->content > *(int *)tmp->content)
				mistakes+=1;
			tmp = tmp->next;
		}
		tmp_outer = tmp_outer->next;
	}
	return (mistakes / total_pairs);
}

void    print_disorder(double disorder)
{
	int percent;
	int decimal;

	percent = (int)(disorder * 100);
	decimal = (int)(disorder * 10000) % 100; 
	ft_putnbr_fd(percent, 2);
	ft_putchar_fd('.', 2);
	if (decimal < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimal, 2);
	ft_putstr_fd(" %\n", 2);
}

void    bench_print(t_stack *stack_a, char *strat)
{
	double disorder;
	
	disorder  = calc_disorder(stack_a);
	ft_putstr_fd("[bench] disorder:  ", 2);
	print_disorder(disorder);
	ft_putstr_fd("[bench] strategy:  ", 2);
	ft_putstr_fd(strat, 2);
	if (ft_strncmp(strat, "simple", 6) == 0)
		ft_putstr_fd(" / O(n\u00B2)\n", 2);
	else if (ft_strncmp(strat, "medium", 6) == 0)
		ft_putstr_fd(" / O(\u221An)\n", 2);
	else if (ft_strncmp(strat, "complex", 7) == 0)
		ft_putstr_fd(" / O(nlog(n))\n", 2);
}
