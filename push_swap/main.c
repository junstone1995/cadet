/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:27:31 by junseole          #+#    #+#             */
/*   Updated: 2021/09/23 23:38:46 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void error()
{
	ft_putstr("Error\n");
	exit(0);
}

int		save_value(int *value, char *s, int size)
{
	char	**split_s;
	int		cnt;
	int		i;
	long long	num;

	split_s = ft_split(s,' ');
	cnt = ft_strlen2(split_s);
	i = 0;
	while (i < cnt)
	{
		num = ft_atoi(split_s[i]);
		if (num >= 2147483648 || num <= -2147483649)
			cnt = -1;
		value[size++] = (int)num;
		i++;
	}
	if (cnt == -1)
		size = -1;
	free(split_s);
	return (size);
}

int		main(int argc, char **argv)
{
	int		i;
	int		size;
	int		*value;

	value = (int *)malloc(sizeof(int) * 500);
	if (!value || argc <= 1)
		return (-1);
	i = 1;
	size = 0;
	while (i < argc)
	{
		size = save_value(value, argv[i],size);

		if (size == -1)
		{
			free(value);
			error();
		}
		i++;
	}

	if (!(is_ascending(value, size)))
	{
		push_start(value,size);
	}
	free(value);
}
