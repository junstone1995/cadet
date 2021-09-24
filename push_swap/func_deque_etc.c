/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_deque_etc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:48:52 by junseole          #+#    #+#             */
/*   Updated: 2021/09/25 06:00:45 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_deque(t_deque *q, int size)
{
	q->value = (int *)malloc(sizeof(int) * (size));
	if (!q->value)
		return ;
	q->front = 0;
	q->rear = 0;
	q->size = size;
}

int	is_full(t_deque *q)
{
	if (((q->rear + 1) % q->size) == q->front)
		return (1);
	return (0);
}

int	is_empty(t_deque *q)
{
	if (q->rear == q->front)
		return (1);
	return (0);
}

void	deque_print(t_deque *q)
{
	int	i;

	i = (q->front + 1) % q->size;
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (is_empty(q))
	{
		printf("공백큐\n");
		return ;
	}
	while (i != q->rear)
	{
		printf("%d | ", q->value[i]);
		i = (i + 1) % q->size;
	}
	printf("%d\n", q->value[i]);
}
