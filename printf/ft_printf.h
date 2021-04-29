/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:29:58 by junseole          #+#    #+#             */
/*   Updated: 2021/04/29 15:29:04 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#indef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"
# include <stdio.h>

# define TYPE "csdiupxX%"

typedef struct	s_info
{
	int			minus;
	int			zero;
	int			width;
	int			precsion;
	int			nbr_base;
	int			nbr_sign;
	char		type;
}				t_info

#endif
