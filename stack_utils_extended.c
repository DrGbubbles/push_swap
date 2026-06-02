/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_extended.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:15:52 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/02 13:13:21 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_number(char *arg, t_stack *a)
{
	long	num;
	int		*ptr;

	if (!is_valid_int(arg))
		return (0);
	num = ft_atol(arg);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	ptr = malloc(sizeof(int));
	if (!ptr)
		return (0);
	*ptr = (int) num;
	if (catch_duplicate(a, *ptr))
	{
		free(ptr);
		return (0);
	}
	ft_new_node(a, ptr);
	return (1);
}

long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	find_max_pos(t_list *lst, int max_num)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		if (*(int *)tmp->content == max_num)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}
