/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:42:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/10 17:13:20 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_lstdelone(t_list *lst)
{
	printf("------func : lstdelone------\n");
	char	*cont_tmp;
	t_list	*lst_tmp;

	if (lst->cont != NULL)
	{
		printf("deleting...%s | %p\n", lst->cont, lst->cont);
		cont_tmp = lst->cont;
		free(cont_tmp);
		lst->cont = NULL;
		printf("deleted! %s | %p by %p\n", lst->cont, cont_tmp, lst->cont);
	}
	lst_tmp = lst;
	if (lst->next == NULL)
	{
		printf("sturct freeing : %p\n", lst);
		free (lst_tmp);
		lst->cont = NULL;
		printf("sturct free : %p, freed : %p\n", lst, lst_tmp);
	}
	else
	{
		printf("lst->next : %p\n", lst->next);
		printf("lst(origin) : %p\n", lst);
		lst = lst->next;
		printf("lst(stitched) : %p, freeing : %p\n", lst, lst_tmp);
		free(lst_tmp);
		lst->cont = NULL;
	}
}

char	*makelst(int fd, t_list **head, char *buffer)
{
	printf("------func : makelst------\n");
	t_list	*node;
	t_list	*cur;

	cur = *head;
	printf("head->cont : %p, cur->cont : %p\n", (*head)->cont, cur->cont);
	printf("cur : %p\n", cur);
	printf("cur->myfd : %d\n", cur->myfd);
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
	printf("new node! %s | %p\n", node->cont, node);
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
	printf("------func : make_line------\n");
	char			*ret;
	char			*tmp;
	ssize_t			len;

	printf("(ml_init)cur->cont : %p\n", cur->cont);
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
			printf("(ml)cur->cont : %p\n", cur->cont);
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
	printf("(ml)cur->cont : %p\n", cur->cont);
	return (ret);
}

char	*get_next_line(int fd)
{
	printf("------func : gnl------\n");
	static t_list	*head;
	t_list			*node;
	char			*ret;
	char			*buffer;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (head == NULL)
	{
		node = (t_list *)malloc(sizeof(t_list));
		printf("head node! : %p\n", node);
		if (node == NULL)
			return (NULL);
		node->myfd = fd;
		printf("head->myfd : %d\n", node->myfd);
		node->next = NULL;
		node->cont = NULL;
		head = node;
		printf("head complete : %p\n", head);
	}
	printf("head->cont : %p\n", head->cont);
	ret = makelst(fd, &head, buffer);
	printf("head->cont : %p\n", head->cont);
	if (head->cont == NULL)
	{
		if(head->next != NULL)
			head = head->next;
		else
			head = NULL;
	}
	*buffer = '\0';
	free(buffer);
	return (ret);
}
