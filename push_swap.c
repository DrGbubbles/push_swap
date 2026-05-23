#include "push_swap.h"

static void	ft_new_node(main_stack *list, int *ptr)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = ptr;
	new_node->next = NULL;
	if (!list->head)
		list->head = new_node;
	else
		list->tail->next = new_node;
	list->tail = new_node;
}

static int	catch_duplicate(main_stack *list, int value)
{
	t_list	*current;

	current = list->head;
	while (current)
	{
		if (*(int *)current->content == value)
			return (1);
		current = current->next;
	}
}

static int	is_valid_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	print_stack(char *stack_name, main_stack *stack)
{
	t_list	*tmp;

	tmp = stack->head;
	ft_printf("%s", stack_name);
	while (tmp)
	{
		ft_printf("%d --> ", *(int *)tmp->content);
		tmp = tmp->next;
	}
	ft_printf("NULL\n");
}

int	main(int argc, char **argv)
{
	int			i;
	int			*ptr;
	main_stack	*stack_a;
	main_stack	*stack_b;
	char	*strategy;

	strategy = "adaptive";
	stack_a = malloc(sizeof(main_stack));
	stack_b = malloc(sizeof(main_stack));
	i = 1;
	stack_a->head = NULL;
	stack_a->tail = NULL;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	if (argc > 1)
	{
		if (ft_strncmp(argv[1], "--", 2) == 0)
			{
				strategy = argv[1];
				i++;
			}
		while (i < argc)
		{
			ptr = malloc(sizeof(int));
			*ptr = ft_atoi(argv[i]);
			if (catch_duplicate(stack_a, *ptr) || !is_valid_int(argv[i]))
			{
				ft_putstr_fd("Error\n", 2);
				ft_lstclear(&(stack_a->head), &free);
				free(ptr);
				return (0);
			}
			ft_new_node(stack_a, ptr);
			i++;
		}
	}
	else
		return (0);
	if (ft_strncmp(strategy, "--simple", 8) == 0)
        ft_printf("strategy is --> %s\n", strategy);
    else if (ft_strncmp(strategy, "--complex", 9) == 0)
        ft_printf("strategy is --> %s\n", strategy);
    else if (ft_strncmp(strategy, "--medium", 8) == 0)
        ft_printf("strategy is --> %s\n", strategy);
    else
        ft_printf("strategy is --> adaptive\n");
	
	// TESTING //
		print_stack("STACK A : ", stack_a);
	sa(stack_a);
	print_stack("STACK A : ", stack_a);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	print_stack("STACK A : ", stack_a);
	print_stack("STACK B : ", stack_b);
	rra(stack_a);
	print_stack("STACK A : ", stack_a);
	ra(stack_a);
	print_stack("STACK A : ", stack_a);
}
