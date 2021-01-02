/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:10:49 by junseole          #+#    #+#             */
/*   Updated: 2021/01/01 23:38:21 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cs;
	size_t	size;

	if (!s)
		return (0);
	cs = (char *)malloc(sizeof(char) * (len + 1));
	if (!cs)
		return (0);
	size = ft_strlen(s);
	if (size <= start)
	{
		*cs = 0;
		return (cs);
	}
	ft_strlcpy(cs, s + start, len + 1);
	return (cs);
}
