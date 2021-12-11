/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:43:27 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/11 13:22:22 by jaesjeon         ###   ########.fr       */
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
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *s);
char	*gft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isinnl(t_list *cur_lst);

void	gft_lstdelone(t_list *lst, t_list *prev);
char	*makelst(int fd, t_list **head, char *buffer);
int		read_line(int fd, t_list *cur, t_list *prev, char *buffer);
char	*make_line(int fd, t_list *cur, t_list *prev, char *buffer);
char	*get_next_line(int fd);

#endif
