/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:27:06 by junseole          #+#    #+#             */
/*   Updated: 2021/04/30 19:00:39 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_type(va_list ap, t_info *info)
{
	int		ret;

	ret = 0;
	if (info->type == 'c')
		ret = print_char(va_arg(ap, int), info);
	else if (info->type == '%')
		ret = print_char('%', info);
	else if (info->type == 's')
		ret = print_string(va_arg(ap, char *), info);
	else if (info->type == 'd' || info->type == 'i')
		ret = print_nbr(va_arg(ap, int), info);
	else if (info->type == 'x' || info->type == 'X' || info->type == 'u')
		ret = print_nbr(va_arg(ap, unsigned int), info);
	else if (info->type == 'p')
		ret = print_nbr(va_arg(ap, unsigned long long), info);
	return (ret);
}

void	check_width_and_prec(va_list ap, char c, t_info *info)
{
	if (ft_isdigit(c))
	{
		if (info->precsion == -1)
			info->width = info->width * 10 + c - 48;
		else
			info->precsion = info->precsion * 10 + c - 48;
	}
	else if (c == '*')
	{
		if (info->precsion == -1)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->precsion = va_arg(ap, int);
	}
}

void	check_info(va_list ap, char c, t_info *info)
{
	if (c == '0' && info->width == 0 && info->precsion == -1)
		info->zero = 1;
	else if (c == '-')
		info->minus = 1;
	else if (c == '.')
		info->precsion = 0;
	else if (ft_isdigit(c) || c == '*')
		check_width_and_prec(ap, c, info);
}

int		parse(va_list ap, char *format)
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
			while (++(*format) && !(ft_strchr(TYPE, format[i])))
				check_info(ap, *format, info);
			info->type = *format++;
			if ((info->minus == 1 || info->precsion > -1) && info->type != '%')
				info->zero = 0;
			ret += print_type(ap, info);
		}
		else
			ret += ft_putchar(*format++);
	}
	free(info);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = parse(ap, (char *)format);
	va_end(ap);
	return (ret);
}
