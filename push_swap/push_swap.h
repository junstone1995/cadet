/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:19:50 by junseole          #+#    #+#             */
/*   Updated: 2021/09/21 20:48:50 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define deque_max 500
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_deque
{
	int *value;
	int rear;
	int front;
}				t_deque;

void	init_deque(t_deque *q);
void	add_rear(t_deque *q, int value);
void	add_front(t_deque *q, int value);
int		delete_rear(t_deque *q);
int		delete_front(t_deque *q);

#endif
