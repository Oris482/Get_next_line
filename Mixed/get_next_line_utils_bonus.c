/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:42:18 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/23 20:16:46 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gft_strlen(char *disk_fd)
{
	size_t	len;

	len = 0;
	while (*disk_fd++ != '\0')
		len++;
	return (len);
}

int	find_nl(char *disk_fd)
{
	int	idx;

	idx = 0;
	while (*disk_fd != '\0')
	{
		if (*disk_fd == '\n')
			return (idx);
		disk_fd++;
		idx++;
	}
	return (-1);
}

void	copy_content(char *disk_fd, t_list *lst, int nl_idx)
{
	char	*content;
	int		idx;

	if (lst == NULL)
	{
		idx = 0;
		while (disk_fd[nl_idx + 1] != '\0')
			disk_fd[idx++] = disk_fd[1 + nl_idx++];
		disk_fd[idx] = '\0';
		return ;
	}
	lst->content = (char *)malloc(BUFFER_SIZE + 1);
	content = lst->content;
	if (content == NULL)
		return ;
	if (nl_idx == -1)
		while (*disk_fd != '\0')
			*content++ = *disk_fd++;
	else
	{
		while (*disk_fd != '\n')
			*content++ = *disk_fd++;
		*content++ = *disk_fd;
	}
	*content = '\0';
}

t_list	*new_lst(char *disk_fd)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	copy_content(disk_fd, node, find_nl(disk_fd));
	if (node->content == NULL)
		return (NULL);
	node->next = NULL;
	return (node);
}

void	del_lst(t_list **cur)
{
	t_list	*tmp;
	t_list	*lst;

	lst = *cur;
	tmp = lst;
	if (lst->content != NULL)
	{
		free(lst->content);
		lst->content = NULL;
	}
	free (lst);
	tmp = NULL;
}
