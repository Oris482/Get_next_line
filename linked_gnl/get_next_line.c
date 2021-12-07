/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:42:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/07 21:35:25 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstdelone(t_list *lst)
{
	if (lst == NULL)
		return ;
	free(lst->cont);
	lst->cont = NULL;
	lst = lst->next;
}

char	*makelst(int fd, t_list *head, char *buffer)
{
	if (head == NULL)
	{
		head = (t_list *)malloc(sizeof(t_list));
		if (head == NULL)
			return (NULL);
		head->myfd = fd;
		head->next = NULL;
		head->cont = NULL;
	}
	while (head->next != NULL)
	{
		if (head->myfd == fd)
			return (make_line(fd, head, buffer));
		head = head->next;
	}
	return (make_line(fd, head, buffer));
}

char	*make_line(int fd, t_list *cur, char *buffer)
{
	char			*ret;
	char			*tmp;
	ssize_t			len;

	if (cur->cont == NULL || ft_isinnl(cur) == -1)
	{
		while (ft_isinnl(cur) == -1)
		{
			len = read(fd, buffer, BUFFER_SIZE);
			if (len < 1)
				break ;
			buffer[len] = '\0';
			tmp = ft_strjoin(cur->cont, buffer);
			free(cur->cont);
			cur->cont = tmp;
		}
		if (cur->cont == NULL || *(cur->cont) == '\0')
		{
			ft_lstdelone(cur);
			return (NULL);
		}
	}
	if (ft_isinnl(cur) == -1)
	{
		ret = ft_strdup(cur->cont);
		tmp = ft_strdup("");
		ft_lstdelone(cur);
	}
	else
	{
		ret = ft_substr(cur->cont, 0, ft_isinnl(cur) + 1);
		tmp = ft_substr(cur->cont, ft_isinnl(cur) + 1, ft_strlen(cur->cont));
		free(cur->cont);
	}
	cur->cont = tmp;
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*ret;
	char			*buffer;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	ret = makelst(fd, head, buffer);
	free(buffer);
	return (ret);
}
