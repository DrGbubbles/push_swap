/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:43:34 by ktaher            #+#    #+#             */
/*   Updated: 2026/05/04 14:45:10 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t num, size_t size )
{
	void	*loc;

	if (size > 0 && num > ((size_t) - 1) / size) 
		return (NULL);
	loc = malloc(num * size);
	if (!loc)
		return (NULL);
	ft_bzero(loc, num * size);
	return (loc);
}
