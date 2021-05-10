/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:30:44 by junseole          #+#    #+#             */
/*   Updated: 2021/05/10 18:33:37 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_prop(t_property *prop)
{
	prop->minus = 0;
	prop->zero = 0;
	prop->width = 0;
	prop->prec = -1;
	prop->base = 10;
	prop->type = 0;
	prop->sign = 0;
}
