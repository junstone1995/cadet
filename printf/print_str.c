/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:24:59 by junseole          #+#    #+#             */
/*   Updated: 2021/05/06 16:51:46 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*parse_buf(char *str, int end, int len)
{
	int		i;
	char	*buf;

	i = 0;
	if (end < len)
	{
		if (!(buf = (char *)malloc(sizeof(char) * end + 1)))
			return (0);
		while (i < end)
			buf[i] = str[i++];
	}
	else
	{
		if (!(buf = (char *)malloc(sizeof(char) * len + 1)))
			return (0);
		while (i < len)
			buf[i] = str[i++];
	}
	buf[i] = '\0';
	return (buf);
}

int		push_str(char **buf, t_info *info)
{
	char	*width;
	int		i;

	if (info->width <= (int)ft_strlen(*buf))
		return ((int)ft_strlen(*buf));
	width = (char *)malloc(sizeof(char) * (info->width - ft_strlen(*buf) + 1));
	i = 0;
	while ((size_t)i < info->width - ft_strlen(*buf))
	{
		if (info->zero == 1)
			width[i] = '0';
		else
			width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	if (info->minus == 0)
		*buf = ft_strjoin(width, *buf);
	else
		*buf = ft_strjoin(*buf, width);
	return (info->width);
}

int		print_str(char *str, t_info *info)
{
	int		ret;
	sizt_t	len;
	char	*buf;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (info->precsion == -1 || (size_t)info->precsion > len)
		info->precsion = len;
	buf = parse_buf(str, info->precsion, len)
	ret = push_str(&buf, info);
	ft_putstr(buf);
	free(buf);
	return (ret);
}
