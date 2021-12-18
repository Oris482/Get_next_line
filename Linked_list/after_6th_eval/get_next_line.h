/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:43:27 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/19 00:27:45 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*cont;
	int				myfd;
	size_t			length;
	int				nlidx;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

size_t	gft_strlen(const char *s);
char	*gft_strjoin(char const *s1, char const *s2, ssize_t s2_len);
char	*gft_substr(char const *s, unsigned int start, size_t len);
int		gft_isinnl(char *cont);
t_list	*gft_lstnew(int fd);

char	*get_next_line(int fd);

#endif
