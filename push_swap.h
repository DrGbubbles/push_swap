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

typedef struct main_stack
{
	t_list	*head;
	t_list	*tail;
}main_stack;

void	sa(main_stack *stack);
void	sb(main_stack *stack);
void	ss(main_stack *a, main_stack *b);
void	pb(main_stack *a, main_stack *b);
void	pa(main_stack *a, main_stack *b);
void    rra(main_stack   *stack);
void    rrb(main_stack   *stack);
void	rrr(main_stack *a, main_stack *b);
void	ra(main_stack   *stack);
void	rb(main_stack   *stack);
void	rr(main_stack *a, main_stack *b);
void	print_stack(char *stack_name, main_stack *stack);
#endif