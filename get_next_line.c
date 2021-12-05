/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:42:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/05 21:28:57 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	initialize(int fd, char **disk, ssize_t len)
{
	if (len == 0)
		return (1);
	if (disk[fd] == 0)
	{
		disk[fd] = ft_strdup("");
		if (disk[fd] == NULL)
			return (0);
		return (1);
	}
	else
		return (1);
}

char	*make_line(char **disk_fd, char *buffer, int nl_idx, ssize_t len)
{
	char	*ret;
	char	*tmp;
	size_t	str_len;

	tmp = *disk_fd;
	*disk_fd = ft_strjoin(*disk_fd, buffer);
	free(tmp);
	if (len > 0)
		str_len = ft_strlen(buffer);
	else
		str_len = ft_strlen(*disk_fd);
	if (nl_idx == -1)
	{
		ret = *disk_fd;
		*disk_fd = NULL;
	}
	else
	{
		ret = ft_substr(*disk_fd, 0, nl_idx);
		tmp = *disk_fd;
		*disk_fd = ft_substr(*disk_fd, nl_idx + 1, (str_len - nl_idx - 1));
		free(tmp);
	}
	return (ret);
}

int	ft_aabb(int fd, char **disk)
{
	int		idx;
	ssize_t	len;

	idx = 0;
	len = ft_strlen(disk[fd]);
	while (len-- > 0)
	{
		if (disk[fd][idx] == 10)
			return (idx);
		idx++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*disk[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	char		*result;
	ssize_t		len;
	int			nl_idx;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (!disk[fd] || (disk[fd] && ft_aabb(fd, disk) == -1))
		len = read(fd, buffer, BUFFER_SIZE);
	else
		len = 0;
	if (len == -1)
		return (NULL);
	if (!initialize(fd, disk, len))
		return (NULL);
	while (len >= 0)
	{
		if (disk[fd] == NULL)
			return (NULL);
		buffer[len] = '\0';
		nl_idx = ft_isinnl(fd, buffer, disk, len);
		result = make_line(&disk[fd], buffer, nl_idx, len);
		if (nl_idx != -1)
			break ;
		len = read(fd, buffer, BUFFER_SIZE);
	}
	return (result);
}
