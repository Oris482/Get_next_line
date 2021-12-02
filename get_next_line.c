/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:42:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/02 15:00:44 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buffer_check(char *buffer, char *result)
{
	ssize_t	len;
	
	if (buffer[0] != '\0')
	{
		len = (ssize_t)ft_strlen(buffer);
		*result = 0;
		result = ft_strnjoin(result, buffer, len);
		ft_bzero(buffer, BUFFER_SIZE);
	}
	return (result);
}

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*result;
	char		*tmp;
	ssize_t		len;
	size_t		idx;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	result = (char *)malloc(1);
	if (result == NULL)
		return (NULL);
	*result = 0;
	result = ft_buffer_check(buffer, result);
	len = read(fd, buffer, BUFFER_SIZE);
	while (len > 0)
	{
		idx = ft_isinnl(buffer, len);
		if (idx != 0)
		{
			tmp = result;
			result = ft_strnjoin(result, buffer, idx);
			free(tmp);
			ft_memmovei(buffer, idx, len);
			break ;
		}
		else
		{
			result = ft_strnjoin(result, buffer, len);
			ft_bzero(buffer, BUFFER_SIZE);
		}
		len = read(fd, buffer, BUFFER_SIZE);
	}
	return (result);
}
