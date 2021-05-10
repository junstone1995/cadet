/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:48:42 by junseole          #+#    #+#             */
/*   Updated: 2021/01/01 23:41:08 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
	{
		len++;
		return (len);
	}
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*ret;
	long	nb;
	int		len;

	nb = (long)n;
	len = ft_len(nb);
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	ret[len--] = 0;
	if (nb == 0)
	{
		ret[0] = '0';
		return (ret);
	}
	if (nb < 0)
	{
		ret[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		ret[len--] = '0' + (nb % 10);
		nb /= 10;
	}
	return (ret);
}
