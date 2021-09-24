/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 22:23:38 by junseole          #+#    #+#             */
/*   Updated: 2021/09/24 15:04:38 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ascending(int *value, int size)
{
	int	i;
	int	num;

	i = 1;
	num = value[0];
	while (i < size)
	{
		if (num > value[i])
			return (0);
		num = value[i];
		i++;
	}
	return (1);
}
