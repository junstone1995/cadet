/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 21:05:14 by junseole          #+#    #+#             */
/*   Updated: 2021/07/19 19:08:44 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include "subtool.h"
# include <stdlib.h>

void	bit_send(int pid, char word, char num);
void	send_unit(int pid, char word);
int		ft_nbrlen(long n);
char	*ft_itoa(int n, char *base);
#endif
