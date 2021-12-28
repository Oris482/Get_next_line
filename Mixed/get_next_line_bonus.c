/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:50:16 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/28 19:50:21 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*disk[MAX_FD];
	t_list		*head;
	ssize_t		len;

	if (fd < 0 || fd >= MAX_FD)
		return (NULL);
	if (disk[fd] == NULL)
	{
		disk[fd] = (char *)malloc(BUFFER_SIZE + 1);
		if (disk[fd] == NULL)
			return (NULL);
		*disk[fd] = '\0';
	}
	if (*disk[fd] == '\0')
	{
		len = read(fd, disk[fd], BUFFER_SIZE);
		if (len <= 0)
			return (NULL);
		disk[fd][len] = '\0';
	}
	head = make_llst(fd, disk[fd], &len);
	return (make_line(&head, &len, &disk[fd]));
}

t_list	*make_llst(int fd, char *disk_fd, ssize_t *len)
{
	t_list	*node;
	ssize_t	cur_len;
	int		nl_idx;

	node = new_lst(disk_fd);
	nl_idx = find_nl(disk_fd);
	if (node == NULL)
		return (NULL);
	if (nl_idx == -1)
	{
		cur_len = read(fd, disk_fd, BUFFER_SIZE);
		disk_fd[cur_len] = '\0';
		if (cur_len < 0)
			return (NULL);
		else if (cur_len == 0)
			return (node);
		*len += cur_len;
		node->next = make_llst(fd, disk_fd, len);
		if (node->next == NULL)
			del_lst(&node);
	}
	if (nl_idx != -1)
		copy_content(disk_fd, NULL, nl_idx);
	return (node);
}

char	*make_line(t_list **head, ssize_t *len, char **disk_fd)
{
	char	*line;
	char	*init_line;
	char	*tmp_content;
	t_list	*tmp;

	if (**disk_fd == '\0' && *disk_fd != NULL)
	{
		free(*disk_fd);
		*disk_fd = NULL;
	}
	line = (char *)malloc(*len + 1);
	if (line == NULL)
		return (NULL);
	init_line = line;
	while (*head != NULL)
	{
		tmp = *head;
		tmp_content = tmp->content;
		while (*(tmp->content) != '\0')
			*line++ = *(tmp->content)++;
		*head = (*head)->next;
		ft_dellst(tmp, tmp_content);
	}
	*line = '\0';
	return (init_line);
}

void	ft_dellst(t_list *target, char *content)
{
	free(content);
	target->content = NULL;
	free(target);
}
