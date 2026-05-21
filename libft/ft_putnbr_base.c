/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:17:41 by ktaher            #+#    #+#             */
/*   Updated: 2026/05/21 16:54:01 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(uintptr_t nb, char *base)
{
	int				count;
	unsigned int	base_length;

	count = 0;
	base_length = ft_strlen(base);
	if (nb >= base_length)
	{
		count += ft_putnbr_base(nb / base_length, base);
	}
	count += ft_putchar(base[(nb % base_length)]);
	return (count);
}
