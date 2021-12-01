/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:43:27 by jaesjeon          #+#    #+#             */
/*   Updated: 2021/12/01 19:24:54 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_strnjoin(char const *s1, char const *s2, size_t cnt);
void	ft_memmovei(void *src, size_t idx, size_t len);
int		ft_isinnl(char *buffer, size_t len);

char	*get_next_line(int fd);

#endif
