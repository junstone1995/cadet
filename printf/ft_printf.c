/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:27:06 by junseole          #+#    #+#             */
/*   Updated: 2021/04/13 17:34:31 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->percsion = 0;
	info->nbr_base = 0;
	info->nbr_sign = 1;
	info->type = 0;
}

int		parse_format(va_list ap, char *format)
{
	int		i;
	int		ret;
	t_info	*info;

	i = 0;
	ret = 0;
	if (!(info = malloc(sizeof(t_info))))
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			init_info(info);
			while(*format)
		}
	}
}

int		ft_printf(const char *format, ...)
{
	int		ret;
	va_list ap;

	va_start(ap, format);
	ret = parse_format(ap, (char *)format);
	va_end(ap);
	return (ret);
}
