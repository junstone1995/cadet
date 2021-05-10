/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:45:50 by junseole          #+#    #+#             */
/*   Updated: 2021/05/10 20:05:14 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define TYPE "cspdiuxX%%"

typedef struct	s_property
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	char		type;
	int			base;
	int			sign;
}				t_property;

int				ft_printf(const char *fmt, ...);
int				read_fmt(va_list argp, char *fmt);
void			check_prot(va_list argp, char c, t_property *prop);
void			check_width_prec(va_list argp, char c, t_property *prop);
int				print_type(va_list argp, t_property *prop);
void			init_prop(t_property *prop);
int				print_char(int c, t_property *prop);
int				print_width(t_property *prop);
int				print_str(char *str, t_property *prop);
char			*read_str(char *str,int prec);
int				check_width_str(char **str2, t_property *prop);

#endif
