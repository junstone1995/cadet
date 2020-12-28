/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:40:48 by junseole          #+#    #+#             */
/*   Updated: 2020/12/28 20:34:27 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1,const char *s2, size_t n)
{
	size_t i;
	unsigned char *cs1;
	unsigned char *cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (cs1[i] == cs2[i] && cs1[i] != '\0' && cs2[i] != '\0' && i < n - 1)
	{
		i++;
	}
	return (cs1[i] - cs2[i]);
}
