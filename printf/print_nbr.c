/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:22:41 by junseole          #+#    #+#             */
/*   Updated: 2021/05/05 17:50:25 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prefix_join_pointer(char **bur)
{
	*buf = ft_strjoin("0x", *buf);
	return (ft_strlen(*buf));
}

int		check_precsion_str(unsigned long long nbr, t_info *info, char **bur)
{
	int buf_len;
	int ret;
	int i;

	buf_len = ft_nbrlen(nbr, info);
	if (info->precsion > buf_len)
		ret = info->precsion;
	else
		ret = buf_len;
	if (!(*buf = (char *)malloc(sizeof(char) * ret + 1)))
		return (0);
	i = 0;
	while (buf_len + i < ret)
	{
		(*buf)[i] = '0';
		i++;
	}
	i = 1;
	if (nbr == 0 && info->precsion != 0)
		(*buf)[ret - i] = '0';
	while (nbr)
	{
		(*buf)[ret - i] = ft_baseset(info->type)[nbr % info->nbr_base];
		nbr /= info-> nbr_base;
		i++
	}
	return (buf_len);
}

int		print_nbr(unsigned long long nbr, t_info *info)
{
	char	*buf;
	int		buf_len;
	int		ret;

	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)nbr < 0)
	{
		info->nbr_sign = -1;
		nbr = -nbr;
	}
	buf_len = check_precsion_str(nbr, info, &buf);
}
