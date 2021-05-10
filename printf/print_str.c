/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:16:05 by junseole          #+#    #+#             */
/*   Updated: 2021/05/10 20:00:10 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_width_str(char **str2, t_property *prop)
{
	char	*width;
	size_t	i;

	if (ft_strlen(*str2) >= (size_t)prop->width)
		return ((int)ft_strlen(*str2));
	if (!(width = malloc(sizeof(char) * (prop->width - ft_strlen(*str2)) + 1)))
		return (0);
	i = 0;
	while (i < (size_t)prop->width - ft_strlen(*str2))
	{
		if (prop->zero == 1)
			width[i] = '0';
		else
			width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	if (prop->minus == 1)
		*str2 = ft_strjoin(*str2,width);
	else
		*str2 = ft_strjoin(width,*str2);
	return (prop->width);
}

char		*read_str(char *str,int prec)
{
	size_t	str_len;
	char	*str2;
	int		i;

	str_len = ft_strlen(str);
	if ((size_t)prec >= str_len)
		prec = (int)str_len;
	if (!(str2 = malloc(sizeof(char) * prec + 1)))
		return (0);
	i = 0;
	while(i < prec)
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

int		print_str(char *str, t_property *prop)
{
	int		ret;
	char	*str2;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	if (prop->prec == -1 || prop->prec > (int)ft_strlen(str))
		prop->prec = (int)ft_strlen(str);
	str2 = read_str(str, prop->prec);
	ret = check_width_str(&str2, prop);
	ft_putstr(str2);
	free(str2);
	return (ret);
}
