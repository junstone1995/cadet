Assignment name  : union
Expected files   : union.c
Allowed functions: write
---

두 개의 문자열을 사용하고 복식 없이 표시하는 프로그램을 작성합니다.
문자열 중 하나에 나타나는 문자입니다.

명령줄에 문자가 나타나는 순서대로 표시됩니다.
뒤에 \n이 나옵니다.

인수 수가 2가 아닌 경우 프로그램에 \n이 표시됩니다.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
