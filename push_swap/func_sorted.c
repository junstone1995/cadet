/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 22:23:38 by junseole          #+#    #+#             */
/*   Updated: 2021/10/05 23:56:13 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ascending(int *value, int size)
{
	int	i;
	int	num;

	i = 1;
	num = value[0];
	while (i < size)
	{
		if (num > value[i])
			return (0);
		num = value[i];
		i++;
	}
	return (1);
}

int	find_pivot(t_deque *q, int start, int end)
{
	int	*arr;
	int	i;
	int	num;
	int	size;

	i = 0;
	size = end - start + 1;
	arr = malloc(sizeof(int) * (size));
	if (!arr)
		return (-1);
	while (i < size)
	{
		arr[i] = q->value[i + start];
		i++;
	}
	quick_sort(arr, start, end);
	if (size % 2 == 0)
		num = arr[(end - start) / 2 + 1];
	else
		num = arr[(end - start) / 2];
	free(arr);
	return (num);
}

void	quick_sort(int *arr, int left, int right)
{
	int	pivot;
	int	start;
	int	end;

	if (left >= right)
		return ;
	pivot = left;
	start = left + 1;
	end = right;
	while (start <= end)
	{
		while (arr[pivot] >= arr[start] && start <= right)
			start++;
		while (arr[pivot] <= arr[end] && end > left)
			end--;
		if (start > end)
			swap(&arr[pivot], &arr[end]);
		else
			swap(&arr[start], &arr[end]);
	}
	quick_sort(arr, left, end - 1);
	quick_sort(arr, end + 1, right);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
