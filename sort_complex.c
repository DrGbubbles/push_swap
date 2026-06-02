/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbliard <gbliard@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:44:46 by gbliard           #+#    #+#             */
/*   Updated: 2026/06/02 12:48:37 by gbliard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_n_stack(t_stack *s_a, t_stack *s_b, int n, t_bench *bench)
{
	while (n > 0)
	{
		pb(s_a, s_b, bench);
		rb(s_b, bench);
		n--;
	}
	return ;
}

void	ft_merge_stack(t_stack *s_a, t_stack *s_b, int n_a, t_bench *bench)
{
	int	content_a;
	int	content_b;

	while (s_b->head)
	{
		content_a = *(int *)s_a->head->content;
		content_b = *(int *)s_b->head->content;
		if (n_a == 0 || content_b < content_a)
		{
			pa(s_a, s_b, bench);
			ra(s_a, bench);
		}
		else
		{
			ra(s_a, bench);
			n_a--;
		}
	}
	while (n_a-- > 0)
		ra(s_a, bench);
}

void	merge_sort(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	int		l;
	int		pos;
	int		n;

	l = 1;
	pos = 0;
	n = ft_lstsize(stack_a->head);
	while (l < n)
	{
		while (pos < n - l)
		{
			ft_push_n_stack(stack_a, stack_b, l, bench);
			ft_merge_stack(stack_a, stack_b, ft_min(l, n - pos - l), bench);
			pos += l + ft_min(l, n - pos - l);
		}
		while (pos++ < n)
			ra(stack_a, bench);
		l = 2 * l;
		pos = 0;
	}
}

int	ft_lst_is_rot_sorted(t_stack *s_a)
{
	int		i;
	int		stop;
	t_list	*head;
	int		i_out;

	stop = 0;
	head = s_a->head;
	i = 0;
	if (!head)
		return (0);
	while (head->next)
	{
		if (*(int *)head->content > *(int *)head->next->content)
		{
			stop++;
			i_out = i;
		}
		head = head->next;
		i++;
	}
	if (stop == 0)
		return (0);
	if (stop == 1 && (*(int *)s_a->tail->content < *(int *)s_a->head->content))
		return (i_out + 1);
	return (-1);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
