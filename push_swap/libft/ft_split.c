/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 17:19:35 by junseole          #+#    #+#             */
/*   Updated: 2021/10/19 16:58:45 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_cnt(char const *s, char c)
{
	size_t	cnt;

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

static char	*malloc_char(char **ret, int size)
{
	char	*s;

	s = (char *)malloc(size);
	if (!s)
	{
		free_arr(ret);
		return (0);
	}
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*from;
	size_t	idx;
	size_t	size;

	ret = (char **)malloc(sizeof(char *) * (get_word_cnt(s, c) + 1));
	if (!ret || !s)
		return (free_arr(ret));
	idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = (char *)s;
			while (*s && *s != c)
				++s;
			size = s - from + 1;
			ret[idx] = malloc_char(ret, size);
			ft_strlcpy(ret[idx++], from, size);
		}
		else
			++s;
	}
	ret[idx] = 0;
	return (ret);
}
