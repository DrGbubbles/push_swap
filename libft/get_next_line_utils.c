/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:24:09 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/02 14:10:43 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_new_node_gnl(t_list_gnl *list, char *buffer, int bytes_read)
{
	t_node	*new_node;

	if (bytes_read > 0)
		buffer[bytes_read] = '\0';
	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free(buffer);
		return ;
	}
	new_node->content = buffer;
	new_node->next = NULL;
	if (!list->current)
		list->current = new_node;
	else
		list->appender->next = new_node;
	list->appender = new_node;
}

void	ft_free_list(t_list_gnl *list)
{
	t_node	*tmp;

	while (list->current)
	{
		tmp = list->current->next;
		free(list->current->content);
		free(list->current);
		list->current = tmp;
	}
	list->appender = NULL;
	list->current = NULL;
}

int	ft_read_to_list(int fd, t_list_gnl *list)
{
	char	*buffer;
	int		bytes_read;
	int		i;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		i = -1;
		if (list->current && list->appender)
			while (list->appender->content[++i])
				if (list->appender->content[i] == '\n')
					return (0);
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (-1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return (bytes_read);
		}
		ft_new_node_gnl(list, buffer, bytes_read);
	}
	return (0);
}

char	*ft_copy_line(t_list_gnl *list, char *line)
{
	t_node	*tmp;
	int		i;
	int		j;

	j = 0;
	tmp = list->current;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{
			line[j++] = tmp->content[i];
			if (tmp->content[i] == '\n')
			{
				line[j] = '\0';
				return (line);
			}
			i++;
		}
		tmp = tmp->next;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_strdup_from(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(i + 1);
	if (!dest)
		return (NULL);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
