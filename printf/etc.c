/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:10:29 by junseole          #+#    #+#             */
/*   Updated: 2021/05/08 21:40:40 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->precsion = -1;
	info->nbr_base = 10;
	info->nbr_sign = 1;
	info->type = 0;
}

int		ft_nbrlen(unsigned long long nbr, t_info *info)
{
	int i;

	if (nbr == 0 && info->precsion != 0)
		return (1);
	i = 0;
	while (nbr)
	{
		i++;
		nbr /= info->nbr_base;
	}
	return (i);
}

char	*ft_baseset(char c)
{
	if (c == 'u' || c == 'd' || c == 'i')
		return ("0123456789");
	else if (c == 'x' || c == 'p')
		return ("0123456789abcdef");
	else if (c == 'X')
		return ("0123456789ABCDEF");
	return (0);
}
