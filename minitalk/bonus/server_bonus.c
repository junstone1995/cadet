/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:55:51 by junseole          #+#    #+#             */
/*   Updated: 2021/07/17 18:21:37 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"
#include <stdio.h>

void	fnsig(int sig)
{
	static char		word = 0;
	static int		cnt = 0;

	word <<= 1;
	if (sig == 30)
		word += 1;
	if (cnt == 0)
	{
		write(1, &word, 1);
		word = 0;
		cnt = 0;
	}
	usleep(1);
}

int	main(void)
{
	signal(SIGUSR1, (void *)fnsig);
	signal(SIGUSR2, (void *)fnsig);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
	return (0);
}
