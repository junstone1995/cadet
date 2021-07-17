/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtool_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:57:46 by junseole          #+#    #+#             */
/*   Updated: 2021/07/17 20:51:34 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBTOOL_BONUS_H
# define SUBTOOL_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

void		writeNbr(int n, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
#endif
