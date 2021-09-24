/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:47:27 by junseole          #+#    #+#             */
/*   Updated: 2021/09/25 06:17:11 by junseole         ###   ########.fr       */
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
	pb(&a,&b);
	pb(&a,&b);
	pb(&a,&b);
	pb(&a,&b);
	pb(&a,&b);
	printf("값 %d\n", b.value[4]);
	printf("값 %d\n", b.value[3]);
	printf("값 %d\n", b.value[2]);
	printf("값 %d\n", b.value[1]);
	printf("값 %d\n", b.value[0]);
	rrb(&b);
	printf("rararara\n");
	printf("값 %d\n", b.value[4]);
	printf("값 %d\n", b.value[3]);
	printf("값 %d\n", b.value[2]);
	printf("값 %d\n", b.value[1]);
	printf("값 %d\n", b.value[0]);
	rrb(&b);
	printf("rararara\n");
	printf("값 %d\n", b.value[4]);
	printf("값 %d\n", b.value[3]);
	printf("값 %d\n", b.value[2]);
	printf("값 %d\n", b.value[1]);
	printf("값 %d\n", b.value[0]);
}
