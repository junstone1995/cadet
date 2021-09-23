/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:19:50 by junseole          #+#    #+#             */
/*   Updated: 2021/09/23 23:51:46 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct	s_deque
{
	int *value;
	int rear;
	int front;
}				t_deque;

void	init_deque(t_deque *q, int size);
void	add_rear(t_deque *q, int value, int size);
void	add_front(t_deque *q, int value, int size);
int		delete_rear(t_deque *q, int size);
int		delete_front(t_deque *q, int size);
int		is_ascending(int *value, int size);
void	push_start(int *value, int size);
int		check_value(int *value, int num, int size);
void deque_print(t_deque *q, int size);
int is_empty(t_deque *q);
int is_full(t_deque *q, int size);

#endif
