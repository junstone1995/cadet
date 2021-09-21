/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_deque?.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:48:52 by junseole          #+#    #+#             */
/*   Updated: 2021/09/21 21:48:59 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_full(t_deque *q)
{
	if (((q->rear + 1) % deque_max) == q->front)
		return (1);
	return (0);
}

int is_empty(t_deque *q)
{
	if (q->front == q->rear)
		return (1);
	return (0);
}

void deque_print(t_deque *q) {

	int i = (q->front + 1) % deque_max;

	printf("DEQUE(front=%d rear=%d) = ",q->front,q->rear);

	if (is_empty(q)) {
		printf("공백큐\n");
		return ;
	}
	while (i!=q->rear) {
		printf("%d | ",q->value[i]);
	i = (i + 1) % deque_max;
	}
	printf("%d\n",q->value[i]);

}
