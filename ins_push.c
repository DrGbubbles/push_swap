#include "push_swap.h"

static void	push(main_stack *stack_A, main_stack *stack_B)
{
	t_list	*node;

	if (!stack_A->head)
		return ;
	node = stack_A->head;
	stack_A->head = node->next;
	if (!stack_A->head)
		stack_A->tail = NULL;
	node->next = stack_B->head;
	stack_B->head = node;
	if (!stack_B->tail)
		stack_B->tail = node;
}

void	pb(main_stack *a, main_stack *b)
{
	push(a, b);
	ft_printf("pb\n");
}

void	pa(main_stack *a, main_stack *b)
{
	push(b, a);
	ft_printf("pa\n");
}
