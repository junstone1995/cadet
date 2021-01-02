/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 17:19:35 by junseole          #+#    #+#             */
/*   Updated: 2021/01/01 23:38:10 by junseole         ###   ########.fr       */
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

static void		*ft_free(char **ret)
{
	int i;

	i = 0;
	while (ret[i])
		free(ret[i++]);
	free(ret);
	ret = 0;
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char		**ret;
	char		*tmp;
	size_t		index;
	size_t		size;

	if (!s || !(ret = (char **)malloc(sizeof(char *) * get_word_cnt(s, c) + 1)))
		return (0);
	index = 0;
	while (*s)
	{
		if (*s != c)
		{
			tmp = (char *)s;
			while (*s && *s != c)
				++s;
			size = s - tmp + 1;
			if (!(ret[index] = (char *)malloc(size)))
				return (ft_free(ret));
			ft_strlcpy(ret[index++], tmp, size);
		}
		else
			s++;
	}
	ret[index] = 0;
	return (ret);
}
