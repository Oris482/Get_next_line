/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:42:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/04 02:55:15 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	initialize(int fd, char **disk)
{
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

char	*make_line(int fd, char **disk, char *buffer, int nl_idx)
{
	char	*ret;
	char	*sub;
	char	*tmp;
	size_t	buf_len;

	buf_len = ft_strlen(buffer);
	tmp = disk[fd];
	if (nl_idx == -1)
	{
		disk[fd] = ft_strjoin(disk[fd], buffer);
		ret = disk[fd];
	}
	else
	{
		sub = ft_substr(buffer, 0, nl_idx);
		disk[fd] = ft_strjoin(disk[fd], sub);
		free(sub);
		ret = ft_strdup(disk[fd]);
		free(disk[fd]);
		disk[fd] = ft_substr(buffer, nl_idx + 1, (buf_len - nl_idx - 1));
	}
	free(tmp);
	return (ret);
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
	if (!initialize(fd, disk))
		return (NULL);
	len = read(fd, buffer, BUFFER_SIZE);
	if (len < 1)
		return (NULL);
	while (len > 0)
	{
		buffer[len] = '\0';
		nl_idx = ft_isinnl(buffer, len);
		result = make_line(fd, disk, buffer, nl_idx);
		if (nl_idx != -1)
			break ;
		len = read(fd, buffer, BUFFER_SIZE);
	}
	return (result);
}
