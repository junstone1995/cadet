/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:32:28 by junseole          #+#    #+#             */
/*   Updated: 2021/09/24 14:31:55 by junseole         ###   ########.fr       */
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

#endif
