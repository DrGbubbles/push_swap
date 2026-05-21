#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	*ptr;
	main_stack *stack_A;
	t_list	*new_node;

	i = 1;
	if (argc > 1)
	{
		
		while (i < argc)
		{
			ft_printf("RECARDO");
			*ptr = ft_atoi(argv[i]);
			ft_printf("%d\n", *ptr);
			new_node = ft_lstnew(ptr);
			ft_lstadd_back(&stack_A->lst_A, new_node);
			ft_printf("Input number %i ---- > %d ///// content in node --> %d\n", i, ft_atoi(argv[i]), stack_A->lst_A->content);
			i++;
		}
	}
	else
	{
		ft_printf("No Input!");
	}
	ft_lstclear(&(stack_A->lst_A), &free);
}