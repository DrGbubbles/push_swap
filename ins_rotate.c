#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->head || stack->head == stack->tail)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	stack->tail->next = tmp;
	tmp->next = NULL;
	stack->tail = tmp;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
