/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:08:30 by junseole          #+#    #+#             */
/*   Updated: 2021/02/19 18:08:38 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_buffer
{
	int				fd;
	char			buf[BUFFER_SIZE + 1];
	struct s_buffer	*next;
}					t_buffer;

size_t				ft_strlen(const char *s);
t_buffer			*new_buffer(int fd);
t_buffer			*find_buffer(t_buffer *buffer, int fd);
void				remove_buffer(t_buffer **head, int fd);
int					resize(char **line, size_t len);
int					get_next_line(int fd, char **line);
#endif
