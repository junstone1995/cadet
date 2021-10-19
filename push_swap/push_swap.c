/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:47:27 by junseole          #+#    #+#             */
/*   Updated: 2021/10/19 22:34:49 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_a(t_deque *a, t_deque *b, int len)
{
	while (len--)
		pa(a, b);
	return (len);
}

int	sorted_check(t_deque *q, int len, int order)
{
	int	i;

	i = -1;
	while (++i < len - 1)
	{
		if ((order == 1 && q->value[i] > q->value[i + 1])
			|| (order == 2 && q->value[i] < q->value[i + 1]))
			return (0);
	}
	return (1);
}

void	push_swap(int *value, int size)
{
	t_deque	a;
	t_deque	b;
	int		i;

	init_deque(&a, size);
	init_deque(&b, size);
	i = -1;
	while (++i < size)
		a.value[i] = value[i];
	a.len = size;
	quick_sort_a(&a, &b, a.len);
	free(a.value);
	free(b.value);
}

int	quick_sort_a(t_deque *a, t_deque *b, int len)
{
	int	pivot;
	int	nb_elem;
	int	pushed_under;

	if (sorted_check(a, len, 1))
		return (1);
	if (len <= 3)
	{
		sort_three_a(a, b, len);
		return (1);
	}
	nb_elem = len;
	pivot = find_pivot(a, len);
	pushed_under = 0;
	while (len != nb_elem / 2 + nb_elem % 2)
	{
		if (a->value[0] < pivot && (len--))
			pb(a, b);
		else if ((++pushed_under))
			ra(a);
	}
	while (nb_elem / 2 + nb_elem % 2 != a->len && pushed_under--)
		rra(a);
	return (quick_sort_a(a, b, nb_elem / 2 + nb_elem % 2)
		&& quick_sort_b(a, b, nb_elem / 2));
}

int	quick_sort_b(t_deque *a, t_deque *b, int len)
{
	int	pivot;
	int	nb_elem;
	int	pushed_under;

	if (sorted_check(b, len, 2))
		len = push_a(a, b, len);
	pushed_under = 0;
	if (len <= 3)
	{
		sort_three_b(a, b, len);
		return (1);
	}
	nb_elem = len;
	pivot = find_pivot(b, len);
	while (len != nb_elem / 2)
	{
		if (b->value[0] >= pivot && len--)
			pa(a, b);
		else if (++pushed_under)
			rb(b);
	}
	while (nb_elem / 2 != b->len && pushed_under--)
		rrb(b);
	return (quick_sort_a(a, b, nb_elem / 2 + nb_elem % 2)
		&& quick_sort_b(a, b, nb_elem / 2));
}
