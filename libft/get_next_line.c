/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:24:35 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/02 13:56:23 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_make_line(t_list_gnl *list)
{
	char	*line;
	t_node	*tmp;
	int		i;
	int		j;

	j = 0;
	tmp = list->current;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i] && tmp->content[i] != '\n')
			i++;
		j += i;
		if (tmp->content[i] == '\n')
		{
			j++;
			break ;
		}
		tmp = tmp->next;
	}
	line = malloc(j + 1);
	if (!line)
		return (NULL);
	return (ft_copy_line(list, line));
}

void	ft_clean_list(t_list_gnl *list)
{
	t_node	*tmp;
	char	*left;
	int		i;

	tmp = list->current;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i] && tmp->content[i] != '\n')
			i++;
		if (tmp->content[i] == '\n')
			break ;
		tmp = tmp->next;
	}
	if (!tmp || !tmp->content[i + 1])
		return (ft_free_list(list));
	left = ft_strdup_from(&tmp->content[i + 1]);
	if (!left)
		return (ft_free_list(list));
	ft_free_list(list);
	ft_new_node_gnl(list, left, 0);
	i = 0;
	while (left[i])
		i++;
	list->appender->content[i] = '\0';
}

char	*get_next_line(int fd)
{
	static t_list_gnl	list;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_read_to_list(fd, &list) == -1)
	{
		ft_free_list(&list);
		return (NULL);
	}
	if (!list.current)
		return (NULL);
	line = ft_make_line(&list);
	if (!line)
	{
		ft_free_list(&list);
		return (NULL);
	}
	ft_clean_list(&list);
	return (line);
}
