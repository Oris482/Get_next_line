/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:49:41 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/16 02:09:26 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		idx++;
		s++;
	}
	return (idx);
}

char	*gft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*joined;
	size_t	idx;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = (char *)malloc(s1_len + s2_len + 1);
	if (joined == NULL)
		return (NULL);
	idx = 0;
	while (s1_len-- > 0)
	{
		joined[idx] = s1[idx];
		idx++;
	}
	if (s1 != NULL)
		free((void *)s1);
	while (s2_len-- > 0)
		joined[idx++] = *s2++;
	joined[idx] = '\0';
	return (joined);
}

char	*ft_strdup(const char *s1)
{
	char	*copied;
	size_t	size;
	size_t	idx;

	size = ft_strlen(s1);
	copied = (char *)malloc(size + 1);
	if (copied == NULL)
		return (NULL);
	idx = 0;
	while (size > idx)
		copied[idx++] = *s1++;
	copied[idx] = '\0';
	return (copied);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	str_len;
	size_t	idx;

	str_len = ft_strlen(s);
	if ((str_len - start) < len && str_len > start)
		len = str_len - start;
	else if (str_len <= start)
		len = 0;
	sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	if (start >= str_len)
	{
		*sub = '\0';
		return (sub);
	}
	idx = 0;
	while (s[start] != '\0' && len > 0)
	{
		sub[idx++] = s[start++];
		len--;
	}
	sub[idx] = '\0';
	return (sub);
}

int	ft_isinnl(t_list *cur)
{
	int	idx;

	idx = 0;
	if (cur->cont == NULL)
		return (-1);
	while ((cur->cont)[idx])
	{
		if ((cur->cont)[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}
