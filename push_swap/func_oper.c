/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:48:52 by junseole          #+#    #+#             */
/*   Updated: 2021/10/19 17:14:41 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_deque(t_deque *q, int size)
{
	q->value = (int *)malloc(sizeof(int) * (size));
	if (!q->value)
		return ;
	q->len = 0;
}

void	ss(t_deque *a, t_deque *b)
{
	ft_putstr("ss\n");
	sa(a);
	sb(b);
}

void	rr(t_deque *a, t_deque *b)
{
	ft_putstr("rr\n");
	ra(a);
	rb(b);
}

void	rrr(t_deque *a, t_deque *b)
{
	ft_putstr("rrr\n");
	rra(a);
	rrb(b);
}
