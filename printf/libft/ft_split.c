/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 17:19:35 by junseole          #+#    #+#             */
/*   Updated: 2021/01/09 17:03:31 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_cnt(char const *s, char c)
{
	size_t cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cnt);
}

static char		**free_arr(char **ret)
{
	size_t i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	ret = 0;
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	char	*from;
	size_t	idx;
	size_t	size;

	if (!s || !(ret = (char**)malloc(sizeof(char*) * (get_word_cnt(s, c) + 1))))
		return (0);
	idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = (char*)s;
			while (*s && *s != c)
				++s;
			size = s - from + 1;
			if (!(ret[idx] = (char*)malloc(size)))
				return (free_arr(ret));
			ft_strlcpy(ret[idx++], from, size);
		}
		else
			++s;
	}
	ret[idx] = 0;
	return (ret);
}
