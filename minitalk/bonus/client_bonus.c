/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 21:04:44 by junseole          #+#    #+#             */
/*   Updated: 2021/07/17 21:19:51 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"
#include <stdio.h>

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
	int		j;
	char	*s;

	if (argc == 3)
	{
		i = 0;
		j = 0;
		pid = ft_atoi(argv[1]);
		s = ft_itoa(getpid(), "0123456789");
		while (s[j])
			send_unit(pid, s[j++]);
		send_unit(pid, '\n');
		while (argv[2][i])
			send_unit(pid, argv[2][i++]);
		send_unit(pid, '\n');
		free(s);
	}
	return (0);
}

int	ft_nbrlen(long n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n, char *base)
{
	char	*ret;
	int		base_len;

	base_len = ft_nbrlen(n);
	ret = malloc(sizeof(char) * base_len + 1);
	if (!(ret))
		return (0);
	ret[base_len] = '\0';
	while (--base_len >= 0)
	{
		ret[base_len] = base[(n % 10)];
		n /= 10;
	}
	return (ret);
}
