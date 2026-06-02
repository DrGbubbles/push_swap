/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:03:12 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/02 09:22:03 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!parse_input(argv, 1, stack_a))
		return (error_exit(stack_a, stack_b));
	print_stack("Stack A : ", stack_a);
	print_stack("Stack B : ", stack_b);

	cleanup(stack_a, stack_b);
	return (0);
}

