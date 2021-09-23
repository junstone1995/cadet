/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:30:46 by junseole          #+#    #+#             */
/*   Updated: 2021/09/23 21:52:00 by junseole         ###   ########.fr       */
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
			if (str[i][j] < '0' || str[i][j] > '9')
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (i);
}
