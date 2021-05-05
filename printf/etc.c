/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:10:29 by junseole          #+#    #+#             */
/*   Updated: 2021/05/05 17:44:50 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

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

int		ft_nbrlen(unsigned long long nbr, t_info *info)
{
	int i;

	if (nbr == 0 && info->percsion != 0)
		return (1);
	i = 0;
	while (nbr)
	{
		i++;
		nbr /= info->nbr_base;
	}
	return (i);
}
