/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:10:29 by junseole          #+#    #+#             */
/*   Updated: 2021/04/29 15:10:58 by junseole         ###   ########.fr       */
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
