/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:29:58 by junseole          #+#    #+#             */
/*   Updated: 2021/05/08 21:40:01 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

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
}				t_info;

int				ft_printf(const char *format, ...);
int				parse(va_list ap, char *format);
void			check_info(va_list ap, char c, t_info *info);
void			check_width_and_precsion(va_list ap, char c, t_info *info);
int				print_type(va_list ap, t_info *info);
int				print_char(int c, t_info *info);
int				push_width(int width, int zero);
int				print_str(char *str, t_info *info);
int				push_str(char **buf, t_info *info);
char			*parse_buf(char *str, int end, int len);
int				print_nbr(unsigned long long nbr, t_info *info);
int				check_precsion_str(unsigned long long nbr, t_info *info, char **bur);
int				check_minus(t_info *info, char **buf);
int				check_minus2(int buf_len, t_info *info, char **buf);
int				prefix_join_pointer(char **bur);
void			init_info(t_info *info);
int				ft_nbrlen(unsigned long long nbr, t_info *info);
char			*ft_baseset(char c);

#endif
