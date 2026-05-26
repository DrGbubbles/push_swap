/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:17:53 by ktaher            #+#    #+#             */
/*   Updated: 2026/05/26 17:52:32 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	int			bench;
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		*strategy;

	if (argc < 2)
		return (0);
	bench = 0;
	stack_a = init_stack();
	stack_b = init_stack();
	strategy = strategy_parser(argv, &bench, &i);
	if (!strategy)
		return (error_exit(stack_a, stack_b));
	if (i >= argc)
		return (0);
	if (!parse_input(argv, i, stack_a, stack_b))
		return (error_exit(stack_a, stack_b));
	//print_stack("stack A before --> ", stack_a);
	//print_stack("stack B before --> ", stack_b);
	run_strategy(strategy, &bench, stack_a, stack_b);
	//print_stack("stack A After --> ", stack_a);
	//print_stack("stack B After --> ", stack_b);
	cleanup(stack_a, stack_b);
	return (0);
}
