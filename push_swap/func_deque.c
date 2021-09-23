/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_deque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:24:24 by junseole          #+#    #+#             */
/*   Updated: 2021/09/23 23:46:14 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_deque(t_deque *q, int size)
{
	q->value = (int *)malloc(sizeof(int) * size);
	if (!q->value)
		return ;
	q->front = size - 1;
	q->rear = size - 1;
}

void	add_rear(t_deque *q, int value, int size)
{
	q->rear = (q->rear + 1) % size;
	q->value[q->rear] = value;
}

void	add_front(t_deque *q, int value, int size)
{
	q->value[q->front] = value;
	q->front = (q->front - 1 + size) % size;
}

int		delete_rear(t_deque *q, int size)
{
	int tmp = q->value[q->rear];
	q->rear = (q->rear - 1 + size) % size;
	return (tmp);
}

int		delete_front(t_deque *q, int size)
{
	int tmp = q->value[q->front + 1 % size];
	q->front = (q->front + 1) % size;
	return (tmp);
}
