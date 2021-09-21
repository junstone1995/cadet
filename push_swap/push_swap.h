/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:19:50 by junseole          #+#    #+#             */
/*   Updated: 2021/09/21 14:27:28 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_stack
{
	t_head	*a;
	t_head	*b;
}				t_stack;

typedef struct	s_head
{
	t_node	*node;
	int		size;
}				t_head;

typedef struct	s_node
{
	int		value;
	t_node	*next;
}				t_node;

#endif
