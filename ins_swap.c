#include "push_swap.h"

static void	swap(main_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack->head || !stack->head->next)
		return ;
	first = stack->head;
	second = stack->head->next;
	first->next = second->next;
	second->next = first;
	stack->head = second;
}

void	sa(main_stack *stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	sb(main_stack *stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	ss(main_stack *a, main_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
