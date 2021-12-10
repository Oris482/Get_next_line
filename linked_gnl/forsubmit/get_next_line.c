/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:42:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/10 17:31:29 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstdelone(t_list *lst)
{
	char	*cont_tmp;
	t_list	*lst_tmp;

	if (lst->cont != NULL)
	{
		cont_tmp = lst->cont;
		free(cont_tmp);
		lst->cont = NULL;
	}
	lst_tmp = lst;
	if (lst->next == NULL)
	{
		free (lst_tmp);
		lst->cont = NULL;
	}
	else
	{
		lst = lst->next;
		free(lst_tmp);
		lst->cont = NULL;
	}
}

char	*makelst(int fd, t_list **head, char *buffer)
{
	t_list	*node;
	t_list	*cur;

	cur = *head;
	if (cur->myfd == fd)
		return (make_line(fd, cur, buffer));
	while (cur != NULL)
	{
		if (cur->myfd == fd)
			return (make_line(fd, cur, buffer));
		if (cur->next == NULL)
			break ;
		cur = cur->next;
	}
	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->myfd = fd;
	node->next = NULL;
	node->cont = NULL;
	cur->next = node;
	return (make_line(fd, node, buffer));
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
		ft_lstdelone(cur);
	}
	else
	{
		ret = ft_substr(cur->cont, 0, ft_isinnl(cur) + 1);
		tmp = ft_substr(cur->cont, ft_isinnl(cur) + 1, ft_strlen(cur->cont));
		free(cur->cont);
		cur->cont = tmp;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*ret;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (head == NULL)
	{
		head = (t_list *)malloc(sizeof(t_list));
		if (head == NULL)
			return (NULL);
		head->myfd = fd;
		head->next = NULL;
		head->cont = NULL;
	}
	ret = makelst(fd, &head, buffer);
	if (head->cont == NULL && head->next != NULL)
		head = head->next;
	else if (head->cont == NULL)
		head = NULL;
	*buffer = '\0';
	free(buffer);
	return (ret);
}
