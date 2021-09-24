/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:47:27 by junseole          #+#    #+#             */
/*   Updated: 2021/09/24 15:13:32 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_start(int *value, int size)
{
	t_deque	a;
	t_deque	b;
	int		i;

	i = 0;
	init_deque(&a, size);
	init_deque(&b, size);
	while (i < size)
	{
		add_rear(&a, value[i], size);
		i++;
	}
}
