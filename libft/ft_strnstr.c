/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:20:22 by junseole          #+#    #+#             */
/*   Updated: 2020/12/29 17:35:34 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*a;
	char	*b;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (i < len && *haystack)
	{
		a = (char *)haystack;
		b = (char *)needle;
		j = i;
		while (*b && *a == *b && j < len)
		{
			a++;
			b++;
			j++;
		}
		if (*b == 0)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (0);
}
