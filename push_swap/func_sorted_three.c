/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sorted_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 01:20:08 by junseole          #+#    #+#             */
/*   Updated: 2021/10/20 14:55:56 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_deque *a)
{
	if (a->value[0] < a->value[1] && a->value[0] < a->value[2])
	{
		if (a->value[1] > a->value[2])
		{
			rra(a);
			sa(a);
		}
	}
	else if (a->value[0] > a->value[1] && a->value[0] > a->value[2])
	{
		if (a->value[1] < a->value[2])
			ra(a);
		else
		{
			sa(a);
			rra(a);
		}
	}
	else
	{
		if (a->value[1] < a->value[2])
			sa(a);
		else
			rra(a);
	}
}

void	sort_three_a_2(t_deque *a, t_deque *b, int len)
{
	while (len != 3 || !(a->value[0] < a->value[1]
			&& a->value[1] < a->value[2]))
	{
		if (len == 3 && a->value[0] > a->value[1] && a->value[2])
			sa(a);
		else if (len == 3 && !(a->value[2] > a->value[0]
				&& a->value[2] > a->value[1]))
		{
			pb(a, b);
			len--;
		}
		else if (a->value[0] > a->value[1])
			sa(a);
		else if (len++)
		{
			pa(a, b);
		}
	}
}

void	sort_three_b_2(t_deque *a, t_deque *b, int len)
{
	while (len || !(a->value[0] < a->value[1] && a->value[1] < a->value[2]))
	{
		if (len == 1 && a->value[0] > a->value[1])
			sa(a);
		else if (len == 1 || (len >= 2 && b->value[0] > b->value[1])
			|| (len == 3 && b->value[0] > b->value[2]))
		{
			pa(a, b);
			len--;
		}
		else
			sb(b);
	}
}

void	sort_three_a(t_deque *a, t_deque *b, int len)
{
	if (a->len == 3 && len == 3)
		three_sort(a);
	else if (len == 2)
	{
		if (a->value[0] > a->value[1])
			sa(a);
	}
	else if (len == 3)
		sort_three_a_2(a, b, len);
}

void	sort_three_b(t_deque *a, t_deque *b, int len)
{
	if (len == 1)
		pa(a, b);
	else if (len == 2)
	{
		if (b->value[0] < b->value[1])
			sb(b);
		pa(a, b);
		pa(a, b);
	}
	else if (len == 3)
		sort_three_b_2(a, b, len);
}
