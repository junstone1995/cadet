/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 21:47:36 by junseole          #+#    #+#             */
/*   Updated: 2020/12/28 22:04:16 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst2;
	const char	*src2;

	if (!dst && !src)
		return (0);
	dst2 = dst;
	src2 = src;
	while (n)
	{
		*dst2++ = *src2++;
		n--;
	}
	return (dst);
}
