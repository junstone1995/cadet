/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 23:31:08 by junseole          #+#    #+#             */
/*   Updated: 2020/12/28 21:16:26 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		len;
	char	*ret;

	len = 0;
	while (src[len] != '\0')
		len++;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (0);
	ret[len] = 0;
	while (len >= 0)
	{
		ret[len] = src[len];
		len--;
	}
	return (ret);
}
