#include <unistd.h>

int		ft_check(char *s1, char c, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (s1[j] == c)
			return (0);
		j++;
	}
	return (1);
}

void inter(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i] !='\0')
	{
		if (ft_check(s1,s1[i],i))
		{
			j = 0;
			while(s2[j] != '\0')
			{
				if (s1[i] == s2[j])
				{
					write(1,&s1[i],1);
					break;
				}
				j++;
			}
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
	if (argc == 3)
		inter(argv[1],argv[2]);
	write(1,"\n",1);
	return (0);
}
