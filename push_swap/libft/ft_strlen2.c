/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:30:46 by junseole          #+#    #+#             */
/*   Updated: 2021/10/19 22:38:03 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen2(char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (!((str[i][j] >= '0' && str[i][j] <= '9')
				|| str[i][j] == '-' || str[i][j] == '+'))
				return (-1);
			if ((str[i][j] == '+' || str[i][j] == '-') && str[i][j + 1] == '\0')
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}
