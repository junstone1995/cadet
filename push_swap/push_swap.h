/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:19:50 by junseole          #+#    #+#             */
/*   Updated: 2021/10/05 23:43:55 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_deque
{
	int			*value;
	int			rear;
	int			front;
	int			size;
}				t_deque;

void			init_deque(t_deque *q, int size);
void			add_rear_a(t_deque *q, int value);
void			add_front_a(t_deque *q, int value);
int				delete_rear_a(t_deque *q);
int				delete_front_a(t_deque *q);
void			add_rear_b(t_deque *q, int value);
void			add_front_b(t_deque *q, int value);
int				delete_rear_b(t_deque *q);
int				delete_front_b(t_deque *q);
int				is_ascending(int *value, int size);
int				find_pivot(t_deque *q, int start, int end);
void			quick_sort(int *arr, int left, int right);
void			swap(int *a, int *b);
void			push_start(int *value, int size);
void			push_swap(t_deque *a, t_deque *b, int size);
void			sa(t_deque *a);
void			sb(t_deque *b);
void			pa(t_deque *a, t_deque *b);
void			pb(t_deque *a, t_deque *b);
void			ra(t_deque *a);
void			rb(t_deque *b);
void			rra(t_deque *a);
void			rrb(t_deque *b);
void			deque_print(t_deque *q);
int				is_empty(t_deque *q);
int				is_full(t_deque *q);

#endif
