/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:30:44 by junseole          #+#    #+#             */
/*   Updated: 2021/05/11 19:13:37 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_prop(t_property *prop)
{
	prop->minus = 0;
	prop->zero = 0;
	prop->width = 0;
	prop->prec = -1;
	prop->base = 10;
	prop->type = 0;
	prop->sign = 0;
}

int		ft_nbrlen(unsigned long long nbr, t_property *prop)
{
	int		i;

	if (nbr == 0 && prop->prec != 0)
		return (1);
	i = 0;
	while (nbr)
	{
		nbr /= prop->base;
		i++;
	}
	return (i);
}

char		*ft_ulltoa(unsigned long long nbr, char *base, t_property *prop, int base_len)
{
	char	*ret;

	if (!(ret = malloc(sizeof(char) * base_len +1)))
		return (0);
	ret[base_len] = '\0';
	while (--base_len >= 0)
	{
		ret[base_len] = base[(nbr % prop->base)];
		nbr /= prop->base;
	}
	return (ret);
}
