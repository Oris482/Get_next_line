/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:43:27 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/02 14:42:33 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_strnjoin(char const *s1, char const *s2, ssize_t len);
void	ft_memmovei(void *src, size_t idx, ssize_t len);
size_t	ft_isinnl(char *buffer, ssize_t len);

char	*ft_buffer_check(char *buffer, char *result);
char	*get_next_line(int fd);

#endif
