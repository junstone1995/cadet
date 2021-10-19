/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:32:28 by junseole          #+#    #+#             */
/*   Updated: 2021/10/19 16:58:26 by junseole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char *str);
size_t		ft_strlen2(char **str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		**ft_split(char const *s, char c);
int			ft_putchar(char c);
int			ft_putstr(char *str);
long long	ft_atoi(const char *str);
char		**free_arr(char **ret);

#endif
