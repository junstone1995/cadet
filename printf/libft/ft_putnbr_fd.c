/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:03:06 by junseole          #+#    #+#             */
/*   Updated: 2021/01/06 18:57:58 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		re_nbr(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n > 9)
		{
			re_nbr(n / 10, fd);
		}
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	re_nbr(n, fd);
}
