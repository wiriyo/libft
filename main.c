#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*hello = "hello";
	char	*empty = "";
	char	*p;
	int		fail = 0;

	/* 1. เจอ 'l' ตัวแรก -> ตองชี้ที่ index 2 */
	p = ft_strchr(hello, 'l');
	if (p == hello + 2)
		printf("PASS 1: ft_strchr(\"hello\", 'l')  -> \"%s\" (index 2)\n", p);
	else
	{
		printf("FAIL 1: ft_strchr(\"hello\", 'l')  -> index %ld (คาด index 2)\n", (long)(p - hello));
		fail = 1;
	}

	/* 2. 'h' ตัวแรกของ string -> index 0 */
	p = ft_strchr(hello, 'h');
	if (p == hello)
		printf("PASS 2: ft_strchr(\"hello\", 'h')  -> \"%s\" (index 0)\n", p);
	else
	{
		printf("FAIL 2: ft_strchr(\"hello\", 'h')  -> index %ld (คาด index 0)\n", (long)(p - hello));
		fail = 1;
	}

	/* 3. ไมเจอ -> ตองเปน NULL */
	p = ft_strchr(hello, 'z');
	if (p == NULL)
		printf("PASS 3: ft_strchr(\"hello\", 'z')  -> NULL\n");
	else
	{
		printf("FAIL 3: ft_strchr(\"hello\", 'z')  -> \"%s\" (คาด NULL)\n", p);
		fail = 1;
	}

	/* 4. c = '\0' -> ตองชี้ที่ \0 ทายสุด = index 5 (หามเปน NULL!) */
	p = ft_strchr(hello, '\0');
	if (p == hello + 5)
		printf("PASS 4: ft_strchr(\"hello\", '\\0') -> index 5 (\\0 ตัวสุดทาย)\n");
	else
	{
		printf("FAIL 4: ft_strchr(\"hello\", '\\0') -> %s (คาด index 5)\n",
			p ? "ได pointer แตผิดตำแหนง" : "NULL (ผิด!)");
		fail = 1;
	}

	/* 5. string วาง + '\0' -> ตองชี้ที่ index 0 */
	p = ft_strchr(empty, '\0');
	if (p == empty)
		printf("PASS 5: ft_strchr(\"\", '\\0')      -> index 0\n");
	else
	{
		printf("FAIL 5: ft_strchr(\"\", '\\0')      -> %s (คาด index 0)\n",
			p ? "ได pointer แตผิดตำแหนง" : "NULL (ผิด!)");
		fail = 1;
	}

	if (fail == 0)
		printf("\nเยี่ยมมากคา~ ผานทุกเคส! 🎉\n");
	return (0);
}
