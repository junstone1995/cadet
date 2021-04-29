/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:16:03 by junseole          #+#    #+#             */
/*   Updated: 2020/12/29 17:37:34 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	size_t			i;

	if (dst == src || n == 0)
		return (dst);
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	i = 0;
	if (dst2 < src2)
		while (i < n)
		{
			dst2[i] = src2[i];
			i++;
		}
	else
		while (i < n)
		{
			dst2[n - i - 1] = src2[n - i - 1];
			i++;
		}
	return (dst);
}
