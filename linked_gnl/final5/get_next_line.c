/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:42:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/16 02:30:02 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	gft_lstdelone(t_list *lst)
{
	t_list *prev;

	prev = lst->prev;
	if (lst->cont != NULL)
	{
		free(lst->cont);
		lst->cont = NULL;
	}
	if (prev != NULL)
		prev->next = lst->next;
	free(lst);
}

static int	read_line(int fd, t_list *cur, char *buffer)
{
	char		*tmp;
	ssize_t		len;

	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buffer[len] = '\0';
		tmp = gft_strjoin(cur->cont, buffer);
		cur->cont = tmp;
		if (ft_isinnl(cur) != -1)
			break ;
	}
	if (cur->cont == NULL || *(cur->cont) == '\0' || len < 0)
	{
		gft_lstdelone(cur);
		return (-1);
	}
	return (0);
}

static char	*make_line(int fd, t_list *cur,  char *buffer)
{
	char	*ret;
	char	*tmp;

	if (read_line(fd, cur, buffer) == -1)
		return (NULL);
	if (ft_isinnl(cur) == -1)
	{
		ret = ft_strdup(cur->cont);
		gft_lstdelone(cur);
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

static char	*makelst(int fd, t_list **head, char *buffer)
{
	t_list	*node;
	t_list	*cur;

	cur = *head;
	cur->prev = NULL;
	if (cur->myfd == fd)
		return (make_line(fd, cur,  buffer));
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
	node->cont = NULL;
	node->prev = cur;
	node->next = NULL;
	cur->next = node;
	return (make_line(fd, node,  buffer));
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*ret;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
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
	free(buffer);
	return (ret);
}
