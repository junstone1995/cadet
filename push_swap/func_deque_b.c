/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_deque_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 04:48:04 by junseole          #+#    #+#             */
/*   Updated: 2021/09/25 04:51:24 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_rear_b(t_deque *q, int value)
{
	q->value[q->rear] = value;
	q->rear = (q->rear + 1) % q->size;
}

void	add_front_b(t_deque *q, int value)
{
	q->front = (q->front - 1 + q->size) % q->size;
	q->value[q->front] = value;
}

int	delete_rear_b(t_deque *q)
{
	int	tmp;

	q->rear = (q->rear - 1 + q->size) % q->size;
	tmp = q->value[q->rear];
	return (tmp);
}

int	delete_front_b(t_deque *q)
{
	int	tmp;

	q->front = (q->front + 1) % q->size;
	tmp = q->value[q->front];
	return (tmp);
}
