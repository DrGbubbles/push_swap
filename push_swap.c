/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:17:53 by username          #+#    #+#             */
/*   Updated: 2026/06/02 09:15:50 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_bench	*bench_stack;
	char	*strategy;

	if (argc < 2)
		return (0);
	bench_stack = malloc(sizeof(t_bench));
	ft_memset(bench_stack, 0, sizeof(t_bench));
	stack_a = init_stack();
	stack_b = init_stack();
	bench_stack->show_ops = 1;
	strategy = strategy_parser(argv, bench_stack, argc);
	if (!strategy)
		return (error_exit(stack_a, stack_b));
	if (!parse_input(argv, 1, stack_a))
		return (error_exit(stack_a, stack_b));
	run_strategy(strategy, bench_stack, stack_a, stack_b);
	cleanup(stack_a, stack_b);
	return (0);
}
