/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:18:10 by ktaher            #+#    #+#             */
/*   Updated: 2026/05/25 14:18:12 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_new_node(t_stack *list, int *ptr)
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

static int	catch_duplicate(t_stack *list, int value)
{
	t_list	*current;

	current = list->head;
	while (current)
	{
		if (*(int *)current->content == value)
			return (1);
		current = current->next;
	}
	return (0);
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

char	*strategy_parser(char **argv, int *bench, int *start)
{
	char	*strat;
	int		i;

	strat = "--adaptive";
	i = 1;
	while (argv[i] && ft_strncmp(argv[i], "--", 2) == 0)
	{
		if (ft_strncmp(argv[i], "--simple", 8) == 0)
			strat = argv[i];
		else if (ft_strncmp(argv[i], "--medium", 8) == 0)
			strat = argv[i];
		else if (ft_strncmp(argv[i], "--complex", 9) == 0)
			strat = argv[i];
		else if (ft_strncmp(argv[i], "--adaptive", 10) == 0)
			strat = argv[i];
		else if (ft_strncmp(argv[i], "--bench", 7) == 0)
			*bench = 1;
		else
			return (NULL);
		i++;
	}
	*start = i;
	return (strat);
}

int	parse_input(char **argv, int i, t_stack *a, t_stack *b)
{
	int	*ptr;

	while (argv[i])
	{
		if (!is_valid_int(argv[i]))
			return (0);
		ptr = malloc(sizeof(int));
		*ptr = ft_atoi(argv[i]);
		if (catch_duplicate(a, *ptr))
		{
			free(ptr);
			return (0);
		}
		ft_new_node(a, ptr);
		i++;
	}
	return (1);
}
