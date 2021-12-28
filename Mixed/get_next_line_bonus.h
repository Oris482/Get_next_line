/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:42:22 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/28 19:42:12 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef MAX_FD
#  define MAX_FD 256
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list {
	char			*content;
	struct s_list	*next;
}	t_list;

size_t	gft_strlen(char *disk_fd);
int		find_nl(char *disk_fd);
void	copy_content(char *disk_fd, t_list *lst, int nl_idx);
t_list	*new_lst(char *disk_fd);
void	del_lst(t_list **lst);

t_list	*make_llst(int fd, char *disk_fd, ssize_t *len);
char	*make_line(t_list **head, ssize_t *len, char **disk_fd);
void	ft_dellst(t_list *target, char *content);
char	*get_next_line(int fd);

#endif
