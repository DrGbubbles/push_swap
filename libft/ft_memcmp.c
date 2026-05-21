/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:58:28 by ktaher            #+#    #+#             */
/*   Updated: 2026/05/04 17:19:03 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *lhs, const void *rhs, size_t count)
{
	unsigned char	*mem1;
	unsigned char	*mem2;
	size_t			i;

	mem1 = (unsigned char *)lhs;
	mem2 = (unsigned char *)rhs;
	i = 0;
	if (!rhs || !lhs)
		return (0);
	while (i < count)
	{
		if (mem1[i] == mem2[i])
		{
			i++;
		}
		else
		{
			return (mem1[i] - mem2[i]);
		}
	}
	return (0);
}
