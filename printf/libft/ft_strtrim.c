/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:46:59 by junseole          #+#    #+#             */
/*   Updated: 2021/01/01 23:38:37 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
	{
		if (end - 1 < 1)
			break ;
		end--;
	}
	if (start > end)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
