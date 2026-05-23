#include "push_swap.h"

static void	rotate(main_stack *stack)
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

void	ra(main_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(main_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(main_stack *a, main_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
