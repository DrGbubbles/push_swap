/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:26:44 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/01 21:35:56 by ktaher           ###   ########.fr       */
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

/**
 * Swap the first two elements at the top of stack a
 */
void	sa(t_stack *stack);
/**
 * Swap the first two elements at the top of stack b
 */
void	sb(t_stack *stack);
/**
 * Swap the first two elements at the top of stack a and b
 */
void	ss(t_stack *a, t_stack *b);
/**
 * Take the first element at the top of a and put it at the top of b
 */
void	pb(t_stack *a, t_stack *b);
/**
 * Take the first element at the top of b and put it at the top of a
 */
void	pa(t_stack *a, t_stack *b);
/**
 * Shift down all elements of stack a by one
 */
void	rra(t_stack	*stack);
/**
 * Shift down all elements of stack b by one, last -> first
 */
void	rrb(t_stack	*stack);
/**
 * Shift down all elements of stack a and b by one, last -> first
 */
void	rrr(t_stack *a, t_stack *b);
/**
 *  Shift up all elements of stack a by one
 */
void	ra(t_stack	*stack);
/**
 *  Shift up all elements of stack b by one, first -> last
 */
void	rb(t_stack	*stack);
/**
 *  Shift up all elements of stack a and b by one, first -> last
 */
void	rr(t_stack *a, t_stack *b);
void	print_stack(char *stack_name, t_stack *stack);
void	sort_simple(t_stack *a, t_stack *b);
t_stack	*init_stack(void);
int		error_exit(t_stack *a, t_stack *b);
int		process_number(char *arg, t_stack *a);
void	cleanup(t_stack *a, t_stack *b);
int		parse_input(char **argv, int i, t_stack *a);
void	run_strategy(char *strategy, int *bench,
			t_stack *stack_a, t_stack *stack_b);
char	*strategy_parser(char **argv, int *bench, int argc);
void	selection_sorting(t_stack *stack_a, t_stack *stack_b);
long	ft_atol(const char *str);
void	ft_new_node(t_stack *list, int *ptr);
int		catch_duplicate(t_stack *list, int value);
int		is_valid_int(char *str);

void    pair_sort(t_stack *stack_a, t_stack *stack_b);
void    merge_sort(t_stack *stack_a, t_stack *stack_b);
int    ft_lst_is_sorted(t_list *head);
int    ft_lst_is_rot_sorted(t_stack *stack_a);
int	find_min(t_list *lst);
void	bucket_sorting(t_stack *stack_a, t_stack *stack_b);
void    bench_print(t_stack *stack_a, char *strat);
int	is_sorted(t_list *lst);
#endif
