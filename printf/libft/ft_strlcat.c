/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:34:48 by junseole          #+#    #+#             */
/*   Updated: 2020/12/23 16:34:51 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	while (*dst != 0 && len < dstsize)
	{
		len++;
		dst++;
	}
	while (*src != 0 && len + 1 < dstsize)
	{
		*dst++ = *src++;
		len++;
	}
	if (len < dstsize)
		*dst = 0;
	while (*src++ != 0)
		len++;
	return (len);
}
