/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:27:31 by junseole          #+#    #+#             */
/*   Updated: 2021/09/21 22:35:13 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_deque a;
	t_deque b;

	if (argc <= 1)
		return (0);

	init_deque(&a);
	init_deque(&b);

	

	push_swap(a, b , )
	free(a.value);
	free(b.value);
}

for (argc 개수): split해준 배열
	if (split해준 배열 내부 인자 개수 > 2)
		for (split 해준 배열 내부 인자 개수) split 해준 배열 내부 인자를 long long 형태로 바꿔준다
		(long long인 이유 -> int를 넘어서는 숫자도 파악하기 위해) int_arr에 저장
	else split 해준 배열 내부 인자를 long long 형태로 바꿔준다 (long long인 이유 -> int를 넘어서는 숫자도 파악하기 위해) int_arr에 저장
