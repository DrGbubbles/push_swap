/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:54:10 by ktaher            #+#    #+#             */
/*   Updated: 2026/05/06 14:06:42 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **node, void ( *del)(void*))
{
	t_list	*tmp;

	if (!node || !del || *node == NULL)
		return ;
	while (*node)
	{
		tmp = (*node)->next;
		ft_lstdelone(*node, del);
		*node = tmp;
	}
}
