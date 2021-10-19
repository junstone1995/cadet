/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_oper_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:55:44 by junseole          #+#    #+#             */
/*   Updated: 2021/10/19 17:13:37 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *a)
{
	int	tmp;

	ft_putstr("sa\n");
	tmp = a->value[0];
	a->value[0] = a->value[1];
	a->value[1] = tmp;
}

void	pa(t_deque *a, t_deque *b)
{
	int	i;

	ft_putstr("pa\n");
	a->len++;
	i = a->len;
	while (--i > 0)
		a->value[i] = a->value[i - 1];
	a->value[0] = b->value[0];
	i = -1;
	b->len--;
	while (++i < b->len)
		b->value[i] = b->value[i + 1];
}

void	ra(t_deque *a)
{
	int	tmp;
	int	i;

	ft_putstr("ra\n");
	tmp = a->value[0];
	i = -1;
	while (++i < a->len - 1)
		a->value[i] = a->value[i + 1];
	a->value[a->len - 1] = tmp;
}

void	rra(t_deque *a)
{
	int	tmp;
	int	i;

	ft_putstr("rra\n");
	tmp = a->value[a->len - 1];
	i = a->len;
	while (--i > 0)
		a->value[i] = a->value[i - 1];
	a->value[0] = tmp;
}
