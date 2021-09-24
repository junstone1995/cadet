/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_oper_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:55:44 by junseole          #+#    #+#             */
/*   Updated: 2021/09/25 06:11:16 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *a)
{
	int	first;
	int	second;

	first = delete_front_a(a);
	second = delete_front_a(a);
	add_front_a(a, first);
	add_front_a(a, second);
}

void	pa(t_deque *a, t_deque *b)
{
	int	num_b;

	if (is_empty(b))
		return ;
	num_b = delete_rear_b(b);
	add_front_a(a, num_b);
}

void	ra(t_deque *a)
{
	int	top;
	int	i;

	i = a->front;
	top = a->value[a->front];
	while (i < a->rear)
	{
		a->value[i] = a->value[i + 1];
		i++;
	}
	a->value[i] = top;
}

void	rra(t_deque *a)
{
	int	bot;
	int	i;

	i = a->rear;
	bot = a->value[a->rear];
	while (i > 0)
	{
		a->value[i] = a->value[i - 1];
		i--;
	}
	a->value[i] = bot;
}
