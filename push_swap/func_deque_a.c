/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_deque_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:24:24 by junseole          #+#    #+#             */
/*   Updated: 2021/09/25 06:00:21 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_rear_a(t_deque *q, int value)
{
	q->rear = (q->rear + 1) % q->size;
	q->value[q->rear] = value;
}

void	add_front_a(t_deque *q, int value)
{
	q->front = (q->front - 1 + q->size) % q->size;
	q->value[q->front] = value;
}

int	delete_rear_a(t_deque *q)
{
	int	tmp;

	tmp = q->value[q->rear];
	q->rear = (q->rear - 1 + q->size) % q->size;
	return (tmp);
}

int	delete_front_a(t_deque *q)
{
	int	tmp;

	tmp = q->value[q->front];
	q->front = (q->front + 1) % q->size;
	return (tmp);
}
