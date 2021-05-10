/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:10:11 by junseole          #+#    #+#             */
/*   Updated: 2021/05/10 21:35:37 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_nbr_di(int nbr, t_property *prop)
{
	char	*str;
	int		ret;

	ret = 0;
	if (nbr < 0)
	{
		prop->sign = 1;
		nbr *= -1;
	}
	str = ft_itoa(nbr);

}
