/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:45:14 by junseole          #+#    #+#             */
/*   Updated: 2021/05/13 11:49:36 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_type(va_list argp, t_property *prop)
{
	int		ret;

	ret = 0;
	if (prop->type == 'c')
		ret = print_char(va_arg(argp, int), prop);
	else if (prop->type == '%')
		ret = print_char(prop->type, prop);
	else if (prop->type == 's')
		ret = print_str(va_arg(argp, char *), prop);
	else if (prop->type == 'd' || prop->type == 'i')
		ret = print_nbr(va_arg(argp, int), prop, "0123456789");
	else if (prop->type == 'u')
		ret = print_nbr(va_arg(argp, unsigned int), prop, "0123456789");
	else if (prop->type == 'x')
		ret = print_nbr(va_arg(argp, unsigned int), prop, "0123456789abcdef");
	else if (prop->type == 'X')
		ret = print_nbr(va_arg(argp, unsigned int), prop, "0123456789ABCDEF");
	else if (prop->type == 'p')
		ret = print_nbr(va_arg(argp, unsigned long long)
								, prop, "0123456789abcdef");
	return (ret);
}

void	check_width_prec(va_list argp, char c, t_property *prop)
{
	if (ft_isdigit(c))
	{
		if (prop->prec == -1)
			prop->width = prop->width * 10 + c - '0';
		else
			prop->prec = prop->prec * 10 + c - '0';
	}
	else if (c == '*')
	{
		if (prop->prec == -1)
		{
			prop->width = va_arg(argp, int);
			if (prop->width < 0)
			{
				prop->minus = 1;
				prop->width *= -1;
			}
		}
		else
			prop->prec = va_arg(argp, int);
	}
}

void	check_prot(va_list argp, char c, t_property *prop)
{
	if (c == '0' && prop->width == 0 && prop->prec == -1)
		prop->zero = 1;
	else if (c == '-')
		prop->minus = 1;
	else if (c == '.')
		prop->prec = 0;
	else if (ft_isdigit(c) || c == '*')
		check_width_prec(argp, c, prop);
}

int		read_fmt(va_list argp, char *fmt)
{
	t_property	*prop;
	int			ret;

	ret = 0;
	if (!(prop = malloc(sizeof(t_property))))
		return (-1);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			init_prop(prop);
			while (*(++fmt) && !(ft_strchr(TYPE, (char)*fmt)))
				check_prot(argp, (char)*fmt, prop);
			prop->type = *fmt++;
			if ((prop->minus == 1 || prop->prec > -1) && prop->type != '%')
				prop->zero = 0;
			if (prop->type == 'p' || prop->type == 'x' || prop->type == 'X')
				prop->base = 16;
			ret += print_type(argp, prop);
		}
		else
			ret += ft_putchar(*fmt++);
	}
	free(prop);
	return (ret);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	argp;
	int		ret;

	va_start(argp, fmt);
	ret = read_fmt(argp, (char *)fmt);
	va_end(argp);
	return (ret);
}
