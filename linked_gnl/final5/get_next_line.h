/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:43:27 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/16 02:19:25 by jaesjeon         ###   ########.fr       */
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
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *s);
char	*gft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isinnl(t_list *cur_lst);

char	*get_next_line(int fd);

#endif
