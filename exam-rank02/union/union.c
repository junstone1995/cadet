#include <unistd.h>

int		ft_check(char *s, char c, int i)
{
	int j;

	j =0;
	while(j < i)
	{
		if (s[j] == c)
			return (0);
		j++;
	}
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int i;
	int len;

	i = 0;
	while(s1[i])
	{
		if(ft_check(s1,s1[i],i))
			write(1,&s1[i],1);
		i++;
	}
	len = i;
	i = 0;
	while (s2[i])
	{
		if(ft_check(s2,s2[i],i))
		{
			if(ft_check(s1,s2[i],len))
				write(1,&s2[i],1);
		}
		i++;
	}
}

int main(int argc,char *argv[])
{
	if (argc == 3)
		ft_union(argv[1],argv[2]);
	write(1,"\n",1);
	return (0);
}
