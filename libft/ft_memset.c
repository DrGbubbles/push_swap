/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:01:41 by ktaher            #+#    #+#             */
/*   Updated: 2026/05/04 15:01:57 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned char	*ptr;
	unsigned char	val;

	ptr = (unsigned char *)dest;
	val = (unsigned char)c;
	while (count > 0)
	{
		*ptr = val;
		ptr++;
		count--;
	}
	return (dest);
}
