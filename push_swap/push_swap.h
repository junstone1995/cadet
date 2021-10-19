/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:19:50 by junseole          #+#    #+#             */
/*   Updated: 2021/10/19 17:06:33 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_deque
{
	int			*value;
	int			size;
	int			len;
}				t_deque;

void			init_deque(t_deque *q, int size);
int				is_ascending(int *value, int size);
int				find_pivot(t_deque *q, int len);
void			push_swap(int *value, int size);
int				quick_sort_a(t_deque *a, t_deque *b, int len);
int				quick_sort_b(t_deque *a, t_deque *b, int len);
void			sort_three_a(t_deque *a, t_deque *b, int size);
void			sort_three_b(t_deque *a, t_deque *b, int len);
void			sa(t_deque *a);
void			sb(t_deque *b);
void			ss(t_deque *a, t_deque *b);
void			pa(t_deque *a, t_deque *b);
void			pb(t_deque *a, t_deque *b);
void			ra(t_deque *a);
void			rb(t_deque *b);
void			rr(t_deque *a, t_deque *b);
void			rra(t_deque *a);
void			rrb(t_deque *b);
void			rrr(t_deque *a, t_deque *b);
void			error(void);

#endif
