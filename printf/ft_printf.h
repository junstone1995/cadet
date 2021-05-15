/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:45:50 by junseole          #+#    #+#             */
/*   Updated: 2021/05/13 12:34:26 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define TYPE "cspdiuxX%"

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
int				ft_nbrlen(unsigned long long nbr, t_property *prop);
char			*ft_ulltoa(unsigned long long nbr, char *base,
							t_property *prop, int base_len);
int				print_char(int c, t_property *prop);
int				print_width(t_property *prop);
int				print_str(char *str, t_property *prop);
char			*read_str(char *str, int prec);
int				check_width_str(char **str2, t_property *prop);
int				print_nbr(unsigned long long nbr,
							t_property *prop, char *base_set);
void			read_nbr(char **str, t_property *prop, int base_len);
void			check_nbr_width(char **str, t_property *prop);
void			add_minus(char **str, t_property *prop, int base_len);
int				add_prefix(char **str);
#endif
