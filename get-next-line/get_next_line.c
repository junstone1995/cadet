/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:33:54 by junseole          #+#    #+#             */
/*   Updated: 2021/03/03 22:33:23 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		sizeCheck(const char *s)
{
	size_t ret;

	if (!s || *s == '\n')
		return (0);
	ret = 0;
	while(*s && *s != '\n')
	{
		ret++;
		s++;
	}
	return (ret);
}

int		read_buf(t_buf *buf, char **line)
{
	size_t	i;
	size_t	j;
	int		find;

	i = ft_strlen(*line);
	j = sizeCheck(buf->buf);
	if (!(resize(i, j, line)))
		return (-1);
	find = 0;
	j = 0;
	while (buf->buf[j])
	{
		(*line)[i++] = buf->buf[j];
		if (buf->buf[j++] == '\n')
		{
			i--;
			find = 1;
			break;
		}
	}
	(*line)[i] = 0;
	i = 0;
	while (buf->buf[j])
		buf->buf[i++] = buf->buf[j++];
	buf->buf[i] = 0;
	return (find);
}

int		get_next_line(int fd, char **line)
{
	static t_buf	*head;
	t_buf			*buf;
	int				size;
	int				find;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || fd >= 32
				|| (!head && !(head = new_buf(fd)))
				|| !(buf = find_buf(fd, head)))
		return (-1);
	*line = 0;
	if ((find = read_buf(buf,line)))
		return (find);
	while ((size = read(fd, buf->buf, BUFFER_SIZE)) > 0)
	{
		buf->buf[size] = 0;
		if ((find = read_buf(buf, line)))
			return (find);
	}
	erase_buf(fd, &head);
	return (size);
}
