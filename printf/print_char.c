/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:32:30 by junseole          #+#    #+#             */
/*   Updated: 2021/05/10 18:33:14 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_width(t_property *prop)
{
	int ret;

	ret = 1;
	while (ret < prop->width)
	{
		if (prop->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		ret++;
	}
	return (ret - 1);
}

int		print_char(int c, t_property *prop)
{
	int		ret;

	ret = 0;
	if (prop->minus == 1)
		ret += ft_putchar(c);
	ret += print_width(prop);
	if (prop->minus == 0)
		ret += ft_putchar(c);
	return (ret);
}
