/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:06:24 by ktaher            #+#    #+#             */
/*   Updated: 2026/05/04 15:07:03 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	const char	*char_locator;

	char_locator = str;
	while (*char_locator)
	{
		if (*char_locator == (unsigned char)ch)
			return ((char *)char_locator);
		char_locator++;
	}
	if (*char_locator == '\0' && ch == '\0')
	{
		return ((char *)char_locator);
	}
	return (NULL);
}
