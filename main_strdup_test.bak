/* ============================================================
**  test main สำหรับ ft_strdup — เทียบกับ libc strdup
**  compile:  gcc -Wall -Wextra -Werror main.c ft_strdup.c -o test_strdup
**  run:      ./test_strdup   (Windows: test_strdup.exe)
**  วิธีอ่าน: PASS = ได้ pointer ใหม่ (≠ s1) + เนื้อหาตรง libc ครบรวม \0
** ============================================================ */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1);

static int	g_pass;
static int	g_total;
static int	g_total_cases;

/* เทียบ ft_strdup กับ libc: เช็ค 4 อย่าง
** 1. ไม่คืน NULL          2. เป็น pointer ใหม่ (malloc ≠ s1)
** 3. เนื้อหาเท่ากัน (strcmp)  4. ครบรวม \0 (memcmp len+1) */
static void	test_case(const char *s1, const char *label)
{
	char	*got;
	char	*exp;
	int	ok;

	got = ft_strdup(s1);
	exp = strdup(s1);
	g_total++;
	ok = 1;
	if (got == NULL)
	{
		ok = 0;
		printf("       ✗ ft_strdup คืน NULL\n");
	}
	if (ok && got == s1)
	{
		ok = 0;
		printf("       ✗ คืน pointer เดิม — ต้อง malloc ที่อยู่ใหม่!\n");
	}
	if (ok && strcmp(got, exp) != 0)
	{
		ok = 0;
		printf("       ✗ เนื้อหาไม่ตรง: ft=\"%s\" libc=\"%s\"\n", got, exp);
	}
	if (ok && memcmp(got, exp, strlen(exp) + 1) != 0)
	{
		ok = 0;
		printf("       ✗ ต่างกันรวม \\0 (memcmp len+1)\n");
	}
	if (ok)
	{
		g_pass++;
		printf("PASS  [%02d/%02d] %s\n", g_total, g_total_cases, label);
	}
	else
		printf("FAIL  [%02d/%02d] %s\n", g_total, g_total_cases, label);
	free(got);
	free(exp);
}

int	main(void)
{
	g_total_cases = 5;
	printf("ft_strdup — เทียบกับ libc strdup (%d cases)\n", g_total_cases);
	test_case("hello world", "copy 'hello world'");
	test_case("", "empty string (len 0)");
	test_case("a", "single char");
	test_case("42 Bangkok rules!", "long with spaces");
	test_case("tab\tand\nnewline", "escape chars");
	if (g_pass == g_total)
		printf("✅ PASSED %d/%d\n", g_pass, g_total);
	else
		printf("❌ FAILED %d/%d\n", g_pass, g_total);
	return (g_pass == g_total ? 0 : 1);
}
