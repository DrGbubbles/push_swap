/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:51:56 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/01 18:07:25 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// int	ft_putnbr(int x)
// {
// 	int		count;
// 	long	n;

// 	count = 0;
// 	n = (long)x;
// 	if (n < 0)
// 	{
// 		count += ft_putchar('-');
// 		n = -n;
// 	}
// 	if (n >= 10)
// 		count += ft_putnbr(n / 10);
// 	count += ft_putchar((n % 10) + '0');
// 	return (count);
// }

char    *get_after_dec(int x)
{
    char *str_num;
    char    *res;
    int i;
    int j;

    i = 0;
    j = 0;
    res = malloc(1024);
    if (!res)
        printf("FAILED");
    str_num = ft_itoa(x);
    while (j < (int)ft_strlen(str_num))
    {
        if(str_num[j] == '.')
        {
            j++;
            while (str_num[j])
            {
                res[i] = str_num[j];
                i++;
                j++;
            }
        }
        j++;
    }
    free(str_num);
    res[i] = '\0';
    printf("%s\n", res);
    return (res);
    
}

void    float_handler(uintptr_t value, int *count)
{
    printf("INSIDE");
    (void)count;
    char *res = get_after_dec(value);
    printf("%s\n", res);
    free(res);
}