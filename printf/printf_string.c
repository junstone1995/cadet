/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:24:59 by junseole          #+#    #+#             */
/*   Updated: 2021/04/29 16:59:28 by junseole         ###   ########.fr       */
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

int		check_width_str(char **buf, t_info *info)
{
	char	*width;
	int		i;

	if (info->width <= (int)ft_strlen(*buf))
		return ((int)ft_strlen(*buf));

}

int		print_string(char *str, t_info *info)
{
	int		ret;
	sizt_t	len;
	char	*buf;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (info->prec == -1 || (size_t)info->prec > len)
		info->prec = len;
	buf = parse_buf(str, info->prec, len)
	ret = check_width_str(&buf, info);
	ft_putstr(buf);
	free(buf);
	return (ret);
}
