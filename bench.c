/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:33:45 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/01 18:01:27 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// static int get_mean(t_stack *stack_a)
// {
//     long long     sum = 0;
//     int lst_size = ft_lstsize(stack_a->head);
//     t_list *tmp = stack_a->head;
//     while(tmp)
//     {
//         sum += *(int *)tmp->content;
//         tmp = tmp->next;
//     }
//     int mean = sum / lst_size;
//     return (mean);
// }

// static float std_dev(t_stack *stack_a, int mean)
// {
//     double  values = 0;
//     int lst_size = ft_lstsize(stack_a->head);
//     t_list *tmp = stack_a->head;
//     while(tmp)
//     {
//         int num = (*(int *)tmp->content - mean);
//         values += num * num;
//         tmp = tmp->next;
//     }
//     float variance = values / lst_size;
//     float i = 0;
// 	while (i * i < variance)
// 		i++;
//     return (i);
// }

static double calc_disorder(t_stack *stack_a)
{
    double mistakes;
    double total_pairs;
    int i;
    int lst_size;
    int val;
    t_list *tmp;

    mistakes = 0;
    total_pairs = 0;
    lst_size = ft_lstsize(stack_a->head);
    i = 0;
    if (is_sorted(stack_a->head))
        return (0);
    while (i < lst_size)
    {
        tmp = stack_a->head;
        val = *(int *)tmp->content;
        while(tmp)
        {
            total_pairs+=1;
            if (val > *(int *)tmp->content)
                mistakes+=1;
            tmp = tmp->next;
        }
        i++;
    }
    return (mistakes / total_pairs);
}

void    bench_print(t_stack *stack_a)
{
    double disorder;
   
    disorder  = calc_disorder(stack_a);
    printf("[ bench ] disorder : %.2f", disorder);
    ft_printf("%.2f\n", disorder);
}
