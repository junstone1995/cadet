/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:00:20 by junseole          #+#    #+#             */
/*   Updated: 2021/04/29 16:13:35 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(int c, t_info *info)
{
	int ret;

	ret = 0;
	if (info->type == '%' && info->minus == 1)
		info->zero = 0;
	if (info->minus == 1)
		ret += ft_putchar(c);
	ret += put_width(info->put_width, info->zero);
	if (info->minus == 0)
		ret += ft_putchar(c);
	return (ret);
}

int		put_width(int width, int zero)
{
	int ret;
	int len;

	ret = 0;
	len = 1;
	while (len < width)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
		ret++;
	}
	return (ret);
}
