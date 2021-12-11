/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:49:15 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/11 18:54:53 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	gft_lstdelone(t_list *lst, t_list *prev)
{
	if (lst->cont != NULL)
	{
		free(lst->cont);
		lst->cont = NULL;
	}
	if (prev != NULL)
		prev->next = lst->next;
	free(lst);
}

char	*makelst(int fd, t_list **head, char *buffer)
{
	t_list	*node;
	t_list	*prev;
	t_list	*cur;

	cur = *head;
	prev = NULL;
	if (cur->myfd == fd)
		return (make_line(fd, cur, prev, buffer));
	while (cur != NULL)
	{
		prev = cur;
		if (cur->myfd == fd)
			return (make_line(fd, cur, prev, buffer));
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
	return (make_line(fd, node, prev, buffer));
}

int	read_line(int fd, t_list *cur, t_list *prev, char *buffer)
{
	char		*tmp;
	ssize_t		len;

	if (cur->cont == NULL || ft_isinnl(cur) == -1)
	{
		while (ft_isinnl(cur) == -1)
		{
			len = read(fd, buffer, BUFFER_SIZE);
			if (len < 1)
				break ;
			buffer[len] = '\0';
			tmp = gft_strjoin(cur->cont, buffer);
			cur->cont = tmp;
		}
		if (cur->cont == NULL || *(cur->cont) == '\0')
		{
			gft_lstdelone(cur, prev);
			*buffer = '\0';
			return (-1);
		}
	}
	*buffer = '\0';
	return (0);
}

char	*make_line(int fd, t_list *cur, t_list *prev, char *buffer)
{
	char			*ret;
	char			*tmp;

	if (read_line(fd, cur, prev, buffer) == -1)
		return (NULL);
	if (ft_isinnl(cur) == -1)
	{
		ret = ft_strdup(cur->cont);
		gft_lstdelone(cur, prev);
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
