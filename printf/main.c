#include "ft_printf.h"

int main()
{
	int nbr;

	nbr = printf("%-10.3d",12345);
	printf("%d",nbr);
}
