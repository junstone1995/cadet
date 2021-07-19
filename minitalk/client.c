/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 21:04:44 by junseole          #+#    #+#             */
/*   Updated: 2021/07/19 18:10:55 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	bit_send(int pid, char word, char num)
{
	if (word & num)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(1000);
}

void	send_unit(int pid, char word)
{
	size_t	i;

	i = 128;
	while (i > 0)
	{
		bit_send(pid, word, (int)i);
		i /= 2;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	if (argc == 3)
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_unit(pid, argv[2][i]);
			i++;
		}
		send_unit(pid, '\n');
	}
	return (0);
}
