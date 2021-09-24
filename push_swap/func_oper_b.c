/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_oper_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 05:03:13 by junseole          #+#    #+#             */
/*   Updated: 2021/09/25 06:14:07 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_deque *b)
{
	int	first;
	int	second;

	first = delete_rear_b(b);
	second = delete_rear_b(b);
	add_rear_b(b, first);
	add_rear_b(b, second);
}

void	pb(t_deque *a, t_deque *b)
{
	int	num_a;

	if (is_empty(a))
		return ;
	num_a = delete_front_a(a);
	add_rear_b(b, num_a);
}

void	rb(t_deque *b)
{
	int	top;
	int	i;

	i = b->rear;
	top = b->value[b->rear - 1];
	while (i > 0)
	{
		b->value[i] = b->value[i - 1];
		i--;
	}
	b->value[i] = top;
}

void	rrb(t_deque *b)
{
	int	bot;
	int	i;

	i = b->front;
	bot = b->value[b->front];
	while (i < b->rear - 1)
	{
		b->value[i] = b->value[i + 1];
		i++;
	}
	b->value[i] = bot;
}
