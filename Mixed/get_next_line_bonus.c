/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:42:11 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/23 20:21:36 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*disk[MAX_FD];
	t_list		*head;
	ssize_t		len;

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
	if (head == NULL || disk[fd] == NULL || *disk[fd] == '\0')
	{
		free(disk[fd]);
		disk[fd] = NULL;
	}
	return (make_line(head, &len));
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
	else
		disk_fd[0] = '\0';
	return (node);
}

char	*make_line(t_list *head, ssize_t *len)
{
	char	*line;
	char	*init_line;
	char	*tmp_content;
	t_list	*tmp;

	line = (char *)malloc(*len + 1);
	if (line == NULL)
		return (NULL);
	init_line = line;
	while (head != NULL)
	{
		tmp = head;
		tmp_content = head->content;
		while (*(head->content) != '\0')
			*line++ = *(head->content)++;
		free (tmp_content);
		head->content = NULL;
		head = head->next;
		free (tmp);
	}
	*line = '\0';
	return (init_line);
}
