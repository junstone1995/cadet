#include <stdio.h>
#include <stdarg.h>

int
	ft_printf(char const *format, ...);

#ifndef REAL
# define F	r += ft_printf
#else
# define F	r += printf
#endif

int
	main(void)
{
	// char
	// ft_printf("10.0s |%10.0s\n", "Hello");
	// ft_printf("10.s  |%10.s\n", "Hello");
	// ft_printf("10s   |%10s\n", "Hello");
	// ft_printf("10.4s |%10.4s\n", "HEllo");
	// ft_printf("10.7s |%10.7s\n", "HEllo");
	// ft_printf(".7s   |%.7s\n", "HEllo");
	// ft_printf(".3s   |%.3s\n", "HEllo");

	// printf("10.0s |%10.0s\n", "Hello");
	// printf("10.s  |%10.s\n", "Hello");
	// printf("10s   |%10s\n", "Hello");
	// printf("10.4s |%10.4s\n", "HEllo");
	// printf("10.7s |%10.7s\n", "HEllo");
	// printf(".7s   |%.7s\n", "HEllo");
	// printf(".3s   |%.3s\n", "HEllo");

	// d
	// ft_printf("d    |%d\n", 1234);
	// ft_printf("3d   |%3d\n", 1234);
	// ft_printf("7d   |%7d\n", 1234);
	// ft_printf(".d   |%.d\n", 1234);
	// ft_printf(".3d  |%.3d\n", 1234);
	// ft_printf(".6d  |%.6d\n", 1234);
	// ft_printf(".6d  |%.6d\n", -1234);
	// ft_printf("3.3d |%3.3d\n", 1234);
	// ft_printf("3.3d |%3.3d\n", -1234);
	// ft_printf("6.3d |%6.3d\n", 1234);
	// ft_printf("6.3d |%6.3d\n", -1234);
	// ft_printf("3.7d |%3.7d\n", 1234);
	// ft_printf("3.7d |%3.7d\n", -1234);
	// ft_printf("9.7d |%9.7d\n", 1234);
	// ft_printf("9.7d |%9.7d\n", -1234);

	// printf("d    |%d\n", 1234);
	// printf("3d   |%3d\n", 1234);
	// printf("7d   |%7d\n", 1234);
	// printf(".d   |%.d\n", 1234);
	// printf(".3d  |%.3d\n", 1234);
	// printf(".6d  |%.6d\n", 1234);
	// printf(".6d  |%.6d\n", -1234);
	// printf("3.3d |%3.3d\n", 1234);
	// printf("3.3d |%3.3d\n", -1234);
	// printf("6.3d |%6.3d\n", 1234);
	// printf("6.3d |%6.3d\n", -1234);
	// printf("3.7d |%3.7d\n", 1234);
	// printf("3.7d |%3.7d\n", -1234);
	// printf("9.7d |%9.7d\n", 1234);
	// printf("9.7d |%9.7d\n", -1234);

	// x
	ft_printf("x    |%x\n", 1234);
	ft_printf("3x   |%3x\n", 1234);
	ft_printf("7x   |%7x\n", 1234);
	ft_printf(".x   |%.x\n", 1234);
	ft_printf(".3x  |%.3x\n", 1234);
	ft_printf(".6x  |%.6x\n", 1234);
	ft_printf(".6x  |%.6x\n", -1234);
	ft_printf("3.3x |%3.3x\n", 1234);
	ft_printf("3.3x |%3.3x\n", -1234);
	ft_printf("6.3x |%6.3x\n", 1234);
	ft_printf("6.3x |%6.3x\n", -1234);
	ft_printf("3.7x |%3.7x\n", 1234);
	ft_printf("3.7x |%3.7x\n", -1234);
	ft_printf("9.7x |%9.7x\n", 1234);
	ft_printf("9.7x |%9.7x\n", -1234);

	printf("x    |%x\n", 1234);
	printf("3x   |%3x\n", 1234);
	printf("7x   |%7x\n", 1234);
	printf(".x   |%.x\n", 1234);
	printf(".3x  |%.3x\n", 1234);
	printf(".6x  |%.6x\n", 1234);
	printf(".6x  |%.6x\n", -1234);
	printf("3.3x |%3.3x\n", 1234);
	printf("3.3x |%3.3x\n", -1234);
	printf("6.3x |%6.3x\n", 1234);
	printf("6.3x |%6.3x\n", -1234);
	printf("3.7x |%3.7x\n", 1234);
	printf("3.7x |%3.7x\n", -1234);
	printf("9.7x |%9.7x\n", 1234);
	printf("9.7x |%9.7x\n", -1234);
}
