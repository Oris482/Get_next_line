/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:42:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/07 16:01:20 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstdelone(t_list *lst)
{
	if (lst == NULL)
		return ;
	free(lst->content);
	lst->content = NULL;
	lst = lst->next;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*temp;

	current = *lst;
	if (*lst == NULL)
		return ;
	while (current->next != NULL)
	{
		temp = current->next;
		ft_lstdelone(current);
		current = temp;
	}
	ft_lstdelone(current);
	*lst = NULL;
}

t_list	*joinlst(int fd, t_list **head, char *buffer)
{
	t_list	*node;
	char	*joined;

	// list에 node가 전혀 없을 때. 탐색 없이 바로 할당
	if (*head == NULL)
	{
		*head = malloc....
	}
	else {}
	while (head->next != NULL)
	{
		// 찾았을 때.
		if (head->myfd == fd)
		{
			/*
			0123456789
			12
			NULL;
			11
			//fd가 아예 없거나, fd는 있는데 buffer가 빈 문자열 -> read
			//위의 케이스가 아니면 "     "
			5678\n123455555555
			55555555\n

			gnl -> gnl -> read
			read(1) -> 1
			read(1) -> 5
			2\n
			*/
			joined = ft_strjoin(head->content, buffer);
			if (joined == NULL)
				return (NULL);
			free(head->content);
			head->content = joined;
			return (head);
		}
		head = head->next;
	}
	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = buffer;
	node->next = NULL;
	head->next = node;
	return (node);
}

char	*make_line(t_list *cur_lst, ssize_t len)
{
	char			*ret;
	char			*tmp;
	int				nl_idx;

	if (cur_lst->content == NULL || len == -1)
		return (NULL);
	nl_idx = ft_isinnl(cur_lst);
	if (nl_idx != -1)
	{
		ret = ft_substr(cur_lst->content, 0, nl_idx + 1);
		tmp = ft_substr(cur_lst->content, nl_idx + 1, \
				ft_strlen(cur_lst->content));
		free(cur_lst->content);
		cur_lst->content = tmp;
		if (*(cur_lst->content) != '\0')
			return (ret);
	}
	else
		ret = ft_strdup(cur_lst->content);
	ft_lstdelone(cur_lst);
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*cur_lst;
	char			*buffer;
	ssize_t			len;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	len = read(fd, buffer, BUFFER_SIZE);
	while (len > 0)
	{
		buffer[len] = '\0';
		cur_lst = joinlst(fd, head, buffer);
		if (cur_lst->content == NULL)
		{
			ft_lstclear(&head);
			return (NULL);
		}
		if (ft_isinnl(cur_lst) != -1)
			break ;
		len = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (make_line(cur_lst, len));
}
