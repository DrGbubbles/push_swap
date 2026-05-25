/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:26:44 by ktaher            #+#    #+#             */
/*   Updated: 2026/05/21 19:28:30 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct t_stack
{
	t_list	*head;
	t_list	*tail;
}	t_stack;

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	rra(t_stack	*stack);
void	rrb(t_stack	*stack);
void	rrr(t_stack *a, t_stack *b);
void	ra(t_stack	*stack);
void	rb(t_stack	*stack);
void	rr(t_stack *a, t_stack *b);
void	print_stack(char *stack_name, t_stack *stack);
void	sort_simple(t_stack *a, t_stack *b);
t_stack	*init_stack(void);
int		error_exit(t_stack *a, t_stack *b);
void	cleanup(t_stack *a, t_stack *b);
int		parse_input(char **argv, int i, t_stack *a, t_stack *b);
void	run_strategy(char *strategy, int *bench,
			t_stack *stack_a, t_stack *stack_b);
char	*strategy_parser(char **argv, int *bench, int *start);
#endif