#include "get_next_line.h"

char	*ft_strndup(char *s1, int n)
{
	char *s2;
	int 	i;

	i = 0;
	if(!(s2 = malloc(sizeof(char) * n + 1)))
		return (0);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] ='\0';
	return (s2);
}

char	*ft_strchr(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if(s[i] == c)
			return (s+i);
		i++;
	}
	if (c == 0)
		return (s+i);
	else
		return (0);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while(*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *buf;
	int		i;
	int		j;

	i = 0;
	if (!(buf = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (i < ft_strlen(s1))
	{
		buf[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		buf[i] = s2[j];
		i++;
		j++;
	}
	buf[i] = '\0';
	return (buf);
}


int	get_next_line(char **line)
{
	static char *data;
	char		*buf;
	ssize_t		bytes;
	char		*tmp;
	char		*n_ptr;

	if(!(buf = (char *)malloc(sizeof(char) * 2)))
		return	(-1);
	if(!data)
	{
		data = ft_strndup("", 0);
		while ((bytes = read(0, buf, 1) > 0))
		{
			buf[bytes] = '\0';
			tmp = data;
			data = ft_strjoin(data,buf);
			free(tmp);
		}
	}
	free(buf);
	n_ptr = ft_strchr(data, '\n');
	if (n_ptr)
	{
		*line = ft_strndup(data, n_ptr - data);
		data += n_ptr - data + 1;
		return (1);
	}
	else
	{
		*line = ft_strndup(data,ft_strchr(data, '\0') - data);
		return (0);
	}
}
