/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_deque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:24:24 by junseole          #+#    #+#             */
/*   Updated: 2021/09/21 21:47:37 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_deque(t_deque *q)
{
	q->value = (int *)malloc(sizeof(int) * deque_max);
	if (!q->value)
		return ;
	q->front = 0;
	q->rear = 0;
}

void	add_rear(t_deque *q, int value)
{
	q->rear = (q->rear + 1) % deque_max;
	q->value[q->rear] = value;
}

void	add_front(t_deque *q, int value)
{
	q->value[q->front] = value;
	q->front = (q->front - 1 + deque_max) % deque_max;
}

int		delete_rear(t_deque *q)
{
	int tmp = q->value[q->rear];
	q->rear = (q->rear - 1 + deque_max) % deque_max;
	return (tmp);
}

int		delete_front(t_deque *q)
{
	int tmp = q->value[q->front + 1 % deque_max];
	q->front = (q->front + 1) % deque_max;
	return (tmp);
}
