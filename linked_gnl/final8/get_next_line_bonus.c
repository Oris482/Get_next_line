/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:27:44 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/18 14:07:10 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	gft_lstdelone(t_list *lst)
{
	t_list	*prev;
	t_list	*next;

	prev = lst->prev;
	next = lst->next;
	if (lst->cont != NULL)
	{
		free(lst->cont);
		lst->cont = NULL;
	}
	if (next != NULL)
		next->prev = prev;
	if (prev != NULL)
	{
		prev->next = lst->next;
		free(lst);
	}
}

static int	read_line(int fd, t_list *cur)
{
	char		*tmp;
	ssize_t		len;
	char		*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (-1);
	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buffer[len] = '\0';
		tmp = gft_strjoin(cur->cont, buffer);
		cur->cont = tmp;
		if (gft_isinnl(cur) != -1)
			break ;
	}
	free(buffer);
	if (cur->cont == NULL || len < 0 || *(cur->cont) == '\0')
		return (-1);
	return (0);
}

static char	*make_line(int fd, t_list *cur)
{
	char	*ret;
	char	*tmp;

	if (read_line(fd, cur) == -1)
	{
		gft_lstdelone(cur);
		return (NULL);
	}
	if (gft_isinnl(cur) == -1)
	{
		ret = gft_substr(cur->cont, 0, gft_strlen(cur->cont));
		gft_lstdelone(cur);
	}
	else
	{
		ret = gft_substr(cur->cont, 0, gft_isinnl(cur) + 1);
		tmp = gft_substr(cur->cont, gft_isinnl(cur) + 1, gft_strlen(cur->cont));
		free(cur->cont);
		cur->cont = tmp;
		if (*tmp == '\0')
			gft_lstdelone(cur);
	}
	return (ret);
}

static char	*makelst(int fd, t_list **head)
{
	t_list	*node;
	t_list	*cur;

	cur = *head;
	if (cur->myfd == fd)
		return (make_line(fd, cur));
	while (cur != NULL)
	{
		if (cur->myfd == fd)
			return (make_line(fd, cur));
		if (cur->next == NULL)
			break ;
		cur = cur->next;
	}
	node = gft_lstnew(fd);
	if (node == NULL)
		return (NULL);
	node->prev = cur;
	cur->next = node;
	return (make_line(fd, node));
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*tmp;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (head == NULL)
	{
		head = gft_lstnew(fd);
		if (head == NULL)
			return (NULL);
	}
	ret = makelst(fd, &head);
	if (head->cont == NULL)
	{
		tmp = head;
		if (head->next != NULL)
			head = head->next;
		else
			head = NULL;
		free(tmp);
	}
	return (ret);
}
