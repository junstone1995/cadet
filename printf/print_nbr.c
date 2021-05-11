/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:10:11 by junseole          #+#    #+#             */
/*   Updated: 2021/05/11 18:41:46 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_prefix(char **str)
{
	*str = ft_strjoin("0x",*str);
}

void	add_minus(char **str, t_property *prop, int base_len)
{
	if (prop->sign == 1 && prop->zero == 1)
	{
		if (base_len >= prop->width)
			*str = ft_strjoin("-",*str);
		else
			*str[0] = '-';
	}
}

int		check_nbr_width(char **str, t_property *prop)
{
	char	*width;
	size_t	i;

	if (ft_strlen(*str) >= (size_t)prop->width)
		return (0);
	if (!(width = malloc(sizeof(char) * (prop->width - ft_strlen(*str)) + 1)))
		return (0);
	i = 0;
	while (i < (size_t)prop->width - ft_strlen(*str))
	{
		if (prop->zero == 1)
			width[i] = '0';
		else
			width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	if (prop->minus == 1)
		*str = ft_strjoin(*str,width);
	else
		*str = ft_strjoin(width,*str);
	return (0);
}

int		read_nbr(char **str, t_property *prop, int base_len)
{
	int		i;
	char	*prec;

	i = 0;
	if (prop->prec > base_len)
	{
		if (!(prec = malloc(sizeof(char) * (prop->prec - base_len) + 1)))
			return (0);
		while (base_len + i < prop->prec)
		{
			prec[i]= '0';
			i++;
		}
		prec[i] = '\0';
		*str = ft_strjoin(prec, *str);
	}
	if (prop->sign == 1 && prop->zero == 0)
	{
		*str = ft_strjoin("-",*str);
	}
	return (0);
}

int		print_nbr(unsigned long long nbr, t_property *prop, char *base_set)
{
	char	*str;
	int		ret;
	int		base_len;

	ret = 0;
	if ((prop->type == 'd' || prop->type == 'i') && (int)nbr < 0)
	{
		prop->sign = 1;
		nbr *= -1;
	}
	str = ft_ulltoa(nbr, base_set, prop);
	base_len = ft_nbrlen(nbr, prop);
	read_nbr(&str, prop, base_len);
	if (prop->type == 'p')
		add_prefix(&str);
	check_nbr_width(&str, prop);
	add_minus(&str, prop, base_len);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}
