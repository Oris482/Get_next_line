/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:41:53 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/17 15:53:01 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*cont;
	int				myfd;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

size_t	gft_strlen(const char *s);
char	*gft_strjoin(char const *s1, char const *s2);
char	*gft_substr(char const *s, unsigned int start, size_t len);
int		gft_isinnl(t_list *cur_lst);
t_list	*gft_lstnew(int fd);

char	*get_next_line(int fd);

#endif
