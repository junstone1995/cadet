/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:34:23 by junseole          #+#    #+#             */
/*   Updated: 2021/03/03 21:42:18 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

typedef struct		s_buf
{
	int				fd;
	char			buf[BUFFER_SIZE + 1];
	struct s_buf	*next;
}					t_buf;

size_t				sizeCheck(const char *s);
size_t				ft_strlen(const char *s);
t_buf				*new_buf(int fd);
t_buf				*find_buf(int fd, t_buf *buf);
int					read_buf(t_buf *buf, char **line);
int					resize(size_t len, size_t len2, char **line);
void				erase_buf(int fd, t_buf **head);
int					get_next_line(int fd, char **line);

#endif
