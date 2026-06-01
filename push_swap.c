/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:17:53 by username          #+#    #+#             */
/*   Updated: 2026/06/01 23:22:20 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_number(char *arg, t_stack *a)
{
	long	num;
	int		*ptr;

	if (!is_valid_int(arg))
		return (0);
	num = ft_atol(arg);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	ptr = malloc(sizeof(int));
	if (!ptr)
		return (0);
	*ptr = (int) num;
	if (catch_duplicate(a, *ptr))
	{
		free(ptr);
		return (0);
	}
	ft_new_node(a, ptr);
	return (1);
}

long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

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
