/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:43:17 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/02 13:24:36 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (*s++ != '\0')
		idx++;
	return (idx);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n > 0)
	{
		*temp = 0;
		temp++;
		n--;
	}
}

char	*ft_strnjoin(char const *s1, char const *s2, ssize_t len)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*joined;
	size_t	idx;

	s1_len = ft_strlen(s1);
	s2_len = len;
	joined = (char *)malloc(s1_len + s2_len + 1);
	if (joined == NULL)
		return (NULL);
	idx = 0;
	while (s1_len > 0)
	{
		joined[idx++] = *s1++;
		s1_len--;
	}
	while (s2_len > 0)
	{
		joined[idx++] = *s2++;
		s2_len--;
	}
	joined[idx] = '\0';
	return (joined);
}

void	ft_memmovei(void *src, size_t idx, ssize_t len)
{
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;
	size_t				init_len;

	if (src == NULL)
		return ;
	init_len = len;
	tmp_dst = (unsigned char *)src;
	tmp_src = (const unsigned char *)(src + idx);
	while (len - idx  > 0)
	{
		*tmp_dst++ = *tmp_src++;
		len--;
	}
	ft_bzero(src + init_len - idx, idx);
}

size_t	ft_isinnl(char *buffer, ssize_t len)
{
	size_t	idx;

	idx = 0;
	while (len > 0)
	{
		if (*buffer == 10)
			break;
		len--;
		idx++;
		buffer++;
	}
	return (idx);
}
