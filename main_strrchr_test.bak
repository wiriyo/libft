#include <stdio.h>
#include <string.h>
#include "libft.h"

static int	check(const char *s, int c)
{
	char	*mine;
	char	*real;
	int		ok;

	mine = ft_strrchr(s, c);
	real = strrchr(s, c);
	ok = (mine == real);
	printf("[%s] ft_strrchr(\"%s\", %d) -> offset %ld | libc -> offset %ld\n",
		ok ? "PASS" : "FAIL", s, c,
		mine ? (long)(mine - s) : -1,
		real ? (long)(real - s) : -1);
	return (ok);
}

int	main(void)
{
	int	fail;

	fail = 0;
	fail += !check("hello", 'l');
	fail += !check("hello", 'h');
	fail += !check("hello", 'o');
	fail += !check("hello", '\0');
	fail += !check("hello", 'x');
	fail += !check("", '\0');
	fail += !check("", 'a');
	fail += !check("banana", 'a');
	fail += !check("a", 'a');
	fail += !check("test", 't');
	fail += !check("hello world", ' ');
	if (fail == 0)
		printf("\nAll tests passed!\n");
	else
		printf("\n%d test(s) failed!\n", fail);
	return (0);
}
