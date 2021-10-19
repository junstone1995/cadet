/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_oper_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 05:03:13 by junseole          #+#    #+#             */
/*   Updated: 2021/10/19 19:35:41 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_deque *b)
{
	int	tmp;

	ft_putstr("sb\n");
	tmp = b->value[0];
	b->value[0] = b->value[1];
	b->value[1] = tmp;
}

void	pb(t_deque *a, t_deque *b)
{
	int	i;

	ft_putstr("pb\n");
	b->len++;
	i = b->len;
	while (--i > 0)
		b->value[i] = b->value[i - 1];
	b->value[0] = a->value[0];
	i = -1;
	a->len--;
	while (++i < a->len)
		a->value[i] = a->value[i + 1];
}

void	rb(t_deque *b)
{
	int	tmp;
	int	i;

	ft_putstr("rb\n");
	tmp = b->value[0];
	i = -1;
	while (++i < b->len - 1)
		b->value[i] = b->value[i + 1];
	b->value[b->len - 1] = tmp;
}

void	rrb(t_deque *b)
{
	int	tmp;
	int	i;

	ft_putstr("rrb\n");
	tmp = b->value[b->len - 1];
	i = b->len;
	while (--i > 0)
		b->value[i] = b->value[i - 1];
	b->value[0] = tmp;
}
