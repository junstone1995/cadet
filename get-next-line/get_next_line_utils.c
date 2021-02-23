/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:45:25 by junseole          #+#    #+#             */
/*   Updated: 2021/02/23 17:27:11 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t ret;

	if (!s)
		return (0);
	ret = 0;
	while (*s++)
		ret++;
	return (ret);
}

t_buf		*new_buf(int fd)
{
	t_buf *ret;

	if (!(ret = malloc(sizeof(t_buf))))
		return (0);
	ret->fd = fd;
	ret->buf[0] = 0;
	ret->next = 0;
	return (ret);
}

t_buf		*find_buf(int fd, t_buf *buf)
{
	if (buf->fd == fd)
		return (buf);
	if (!buf->next)
		return (buf->next = new_buf(fd));
	return (find_buf(fd, buf->next));
}

int			resize(size_t len, char **line)
{
	char	*new_line;
	size_t	i;

	if (!(new_line = malloc(len + BUFFER_SIZE + 1)))
		return (0);
	i = 0;
	while (i < len)
	{
		new_line[i] = (*line)[i];
		i++;
	}
	new_line[i] = 0;
	free (*line);
	*line = new_line;
	return (1);
}

void		erase_buf(int fd, t_buf **head)
{
	t_buf *pre;
	t_buf *cur;

	pre = *head;
	if (pre->fd == fd)
	{
		cur = pre->next;
		free(pre);
		*head = cur;
		return ;
	}
	while (pre->next->fd != fd)
		pre = pre->next;
	cur = find_buf(fd, *head);
	pre->next = cur->next;
	free(cur);
}

