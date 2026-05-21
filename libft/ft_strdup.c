/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:07:14 by ktaher            #+#    #+#             */
/*   Updated: 2026/05/04 15:08:00 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned char	*source;
	size_t			len;
	size_t			i;
	unsigned char	*ptr;

	source = (unsigned char *)s;
	len = ft_strlen((const char *)source);
	ptr = (unsigned char *)malloc((sizeof(char)) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = source[i];
		i++;
	}
	ptr[i] = '\0';
	return ((char *)ptr);
}
