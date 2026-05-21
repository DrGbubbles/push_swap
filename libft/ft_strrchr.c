/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:10:39 by ktaher            #+#    #+#             */
/*   Updated: 2026/05/04 17:18:50 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	const char	*char_locator;
	int			i;

	char_locator = str;
	i = (int)ft_strlen(str);
	while (i >= 0)
	{
		if ((unsigned char)char_locator[i] == (unsigned char)ch)
		{
			return ((char *)&char_locator[i]);
		}
		i--;
	}
	return (NULL);
}
