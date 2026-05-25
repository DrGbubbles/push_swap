/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:58:01 by ktaher            #+#    #+#             */
/*   Updated: 2026/05/25 14:19:56 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	uc;

	p = (unsigned char *)ptr;
	uc = (unsigned char)ch;
	i = 0;
	while (i < count)
	{
		if (p[i] == uc)
		{
			return ((void *)&p[i]);
		}
		i++;
	}
	return (NULL);
}
