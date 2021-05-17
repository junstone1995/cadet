#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	t_info
{
	int width;
	int perc;
	int base;
	int sign;
	char type;
}				s_info;

int		ft_putchar(int c)
{
	return (write(1,&c,1));
}

int		ft_strchr(char c)
{
	if (c == 's')
		return (0);
	else if (c == 'd')
		return (0);
	else if (c == 'x')
		return (0);
	else
		return (1);
}

void	init_info(s_info *info)
{
	info->base = 10;
	info->width = 0;
	info->perc = -1;
	info->sign = 0;
	info->type = 0;
}

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
void	push_width_prec(char c, s_info *info)
{
	if (info->perc < 0)
		info->width = info->width * 10 + c - '0';
	else
		info->perc = info->perc * 10 + c - '0';
}

void	check_width_prec(char c, s_info *info)
{
	if (c == '.')
		info->perc = 0;
	else if (ft_isdigit(c))
		push_width_prec(c, info);
}

int		ft_strlen(char *s)
{
	int i;
	i = 0;
	while(*s++)
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2,int flag)
{
	char *str;
	int i;
	int j;

	j = 0;
	i = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1)+ft_strlen(s2))+ 1)))
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] ='\0';
	if (flag == 1 || flag == 3)
		free(s1);
	if (flag == 2 || flag == 3)
		free(s2);
	return (str);
}

int		check_width_str(char **s, s_info *info)
{
	char *width;
	int i;

	i = 0;
	if (info->width <= ft_strlen(*s))
		return (ft_strlen(*s));
	if (!(width = malloc(sizeof(char) * (info->width - ft_strlen(*s) + 1))))
		return (0);
	while (i < info->width - ft_strlen(*s))
	{
		width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	*s =ft_strjoin(width,*s,3);
	return (info->width);
}

int		ft_putstr(char *s)
{
	return (write(1,s,ft_strlen(s)));
}

int		print_str(char *str, s_info *info)
{
	int ret;
	int i;
	char *buf;

	i = 0;
	ret = 0;
	if (!str)
		str = "(null)";
	if (info->perc == -1 ||info->perc >= ft_strlen(str))
		info->perc = ft_strlen(str);
	if (!(buf = malloc(sizeof(char) * info->perc + 1)))
		return (0);
	while (i < info->perc)
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	ret = check_width_str(&buf, info);
	ft_putstr(buf);
	free(buf);
	return (ret);
}

int		nbr_len(unsigned long long nbr,s_info *info)
{
	int i;

	i =0;
	while(nbr)
	{
		nbr /= info->base;
		i++;
	}
	return (i);
}

char	*ulltoa(unsigned long long nbr, s_info *info, char *base_set,int base_len)
{
	char *str;

	if (!(str = malloc(sizeof(char) * base_len + 1)))
		return (0);
	str[base_len] = '\0';
	while(--base_len >= 0)
	{
		str[base_len] = base_set[(nbr % info->base)];
		nbr /= info->base;
	}
	return (str);
}

void	check_nbr_perc(char **str, s_info *info)
{
	if (info->perc > ft_strlen(*str))
	{
		int i;

		i = ft_strlen(*str);
		while (i < info->perc)
		{
			*str = ft_strjoin("0",*str, 2);
			i++;
		}
	}
	if (info ->sign == 1)
		*str = ft_strjoin("-",*str, 2);
	if (info->width > ft_strlen(*str))
	{
		int i;

		i = ft_strlen(*str);
		while(i <info->width)
		{
			*str = ft_strjoin(" ",*str,2);
			i++;
		}
	}
}

int		print_nbr(unsigned long long nbr, s_info *info, char *base_set)
{
	int ret;
	int base_len;
	char *str;

	if (info->type == 'd' && (int)nbr < 0)
	{
		info->sign = 1;
		nbr *= -1;
	}
	if (info->type == 'x')
		info->base = 16;
	base_len = nbr_len(nbr,info);
	str = ulltoa(nbr, info, base_set, base_len);
	check_nbr_perc(&str, info);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int		print_type(va_list ap, s_info *info)
{
	int ret;

	ret = 0;
	if (info->type == 's')
		ret += print_str(va_arg(ap, char *), info);
	else if (info->type == 'd')
		ret += print_nbr(va_arg(ap, int), info, "0123456789");
	else if (info->type == 'x')
		ret += print_nbr(va_arg(ap, long long), info, "0123456789abcdef");
	return (ret);
}

int		read_fmt(va_list ap, char *fmt)
{
	int		ret;
	s_info	*info;

	ret = 0;
	if (!(info = malloc(sizeof(s_info))))
		return (-1);
	while(*fmt)
	{
		if(*fmt == '%')
		{
			init_info(info);
			while (*(++fmt) && ft_strchr(*fmt))
				check_width_prec((char)*fmt,info);
			info->type = *fmt++;
			ret += print_type(ap, info);
		}
		else
			ret += ft_putchar(*fmt++);
	}
	free(info);
	return (ret);
}

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	int ret;

	va_start(ap,fmt);
		ret = read_fmt(ap, (char *)fmt);
	va_end(ap);
	return (ret);
}
