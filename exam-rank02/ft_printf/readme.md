Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
---

다음 제약 조건을 사용하여 real printf를 모방하는 'ft_printf' 함수를 작성하십시오.

- s, d, x 변환만 관리합니다.
- 최소 필드 너비를 관리합니다. (0인 필드는 절대 테스트하지 않습니다.)
- 프리셉션 깃발만 관리한다.

기능은 다음과 같이 선언해야 합니다.
int ft_printf(const char *, ... );

Exemples of the function output:

call: ft_printf("%10.2s\n", "toto");
out:        to$

call: ft_printf("Magic %s is %5d", "number", 42);
out:Magic number is    42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out:Hexadecimal for 42 is 2a$
