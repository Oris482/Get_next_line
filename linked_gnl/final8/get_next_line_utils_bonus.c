/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:42:29 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/17 16:45:58 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gft_strlen(const char *s)
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

	s1_len = gft_strlen(s1);
	s2_len = gft_strlen(s2);
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

char	*gft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	str_len;
	size_t	idx;

	str_len = gft_strlen(s);
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

int	gft_isinnl(t_list *cur)
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

t_list	*gft_lstnew(int fd)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->myfd = fd;
	node->cont = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
