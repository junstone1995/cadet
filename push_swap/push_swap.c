/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:47:27 by junseole          #+#    #+#             */
/*   Updated: 2021/10/05 23:51:36 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_start(int *value, int size)
{
	t_deque	a;
	t_deque	b;
	int		i;

	i = 1;
	init_deque(&a, size);
	init_deque(&b, size);
	a.value[0] = value[0];
	while (i < size)
	{
		add_rear_a(&a, value[i]);
		i++;
	}
	push_swap(&a, &b, size);
}

void	push_swap(t_deque *a, t_deque *b, int size)
{
	int pivot;

	pivot = find_pivot(a, a->front, a->rear);
	printf("%d",pivot);
}
