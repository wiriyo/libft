/* ============================================================
**  test main สำหรับ ft_strjoin (Part 2 — ตัวที่ 6)
**  compile:  gcc -Wall -Wextra -Werror main.c ft_strjoin.c ft_strlen.c -o test_strjoin
**  run:      ./test_strjoin
**  วิธีอ่าน: PASS = สตริงที่ได้ตรงกับที่คาด + ต้นฉบับไม่ถูกแก้ + (เคส 8) ต้องเป็นก้อนใหม่
** ============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2);

static int	g_pass;
static int	g_total;
static int	g_cases;

static void	check(const char *label, char *got, const char *exp,
		char *s1, const char *s1_orig, char *s2, const char *s2_orig,
		int must_differ)
{
	int	ok;

	g_total++;
	ok = 1;
	if (got == NULL)
		ok = 0;
	else if (strcmp(got, exp) != 0)
		ok = 0;
	if (strcmp(s1, s1_orig) != 0 || strcmp(s2, s2_orig) != 0)
		ok = 0;
	if (must_differ && (got == s1 || got == s2))
		ok = 0;
	if (ok)
	{
		g_pass++;
		printf("PASS  [%02d/%02d] %-34s -> \"%.60s\"\n",
			g_total, g_cases, label, got);
	}
	else if (got == NULL)
		printf("FAIL  [%02d/%02d] %-34s (ได้ NULL, คาด \"%s\")\n",
			g_total, g_cases, label, exp);
	else
		printf("FAIL  [%02d/%02d] %-34s (ได้ \"%.60s\" คาด \"%s\"%s%s)\n",
			g_total, g_cases, label, got, exp,
			(strcmp(s1, s1_orig) != 0 || strcmp(s2, s2_orig) != 0)
			? " [ต้นฉบับถูกแก้!]" : "",
			(must_differ && (got == s1 || got == s2)) ? " [คืน pointer เดิม]" : "");
	if (got != NULL)
		free(got);
}

int	main(void)
{
	char	s1[] = "Hello ";
	char	s2[] = "World";
	char	s3[] = "";
	char	s4[] = "abc";
	char	s5[] = "abc";
	char	s6[] = "";
	char	s7[] = "";
	char	s8[] = "";
	char	s9[] = "42";
	char	s10[] = " Bangkok";
	char	s11[] = "a";
	char	s12[] = "b";
	char	s13[] = "0123456789";
	char	s14[] = "abcdefghijklmnopqrstuvwxyz";
	char	s15[] = "Hello";
	char	s16[] = "World";
	char	s17[] = " ";
	char	s18[] = " ";

	g_cases = 9;
	printf("ft_strjoin — ต่อสตริง 2 ก้อนเป็นก้อนใหม่ (%d cases)\n", g_cases);
	check("ต่อปกติ \"Hello \"+\"World\"", ft_strjoin(s1, s2),
		"Hello World", s1, "Hello ", s2, "World", 0);
	check("s1 ว่าง \"\"+\"abc\"", ft_strjoin(s3, s4),
		"abc", s3, "", s4, "abc", 0);
	check("s2 ว่าง \"abc\"+\"\"", ft_strjoin(s5, s6),
		"abc", s5, "abc", s6, "", 0);
	check("ว่างทั้งคู่ \"\"+\"\"", ft_strjoin(s7, s8),
		"", s7, "", s8, "", 0);
	check("มีช่องว่าง \"42\"+\" Bangkok\"", ft_strjoin(s9, s10),
		"42 Bangkok", s9, "42", s10, " Bangkok", 0);
	check("ตัวละ 1 (\"a\"+\"b\")", ft_strjoin(s11, s12),
		"ab", s11, "a", s12, "b", 0);
	check("ยาว 10+26", ft_strjoin(s13, s14),
		"0123456789abcdefghijklmnopqrstuvwxyz",
		s13, "0123456789", s14, "abcdefghijklmnopqrstuvwxyz", 0);
	check("ต้องเป็นก้อนใหม่ (ไม่ใช่ s1/s2)", ft_strjoin(s15, s16),
		"HelloWorld", s15, "Hello", s16, "World", 1);
	check("ช่องว่าง 2 ตัว \" \"+\" \"", ft_strjoin(s17, s18),
		"  ", s17, " ", s18, " ", 0);
	if (g_pass == g_total)
		printf("✅ PASSED %d/%d\n", g_pass, g_total);
	else
		printf("❌ FAILED %d/%d — ดู FAIL แล้วแก้ฟังก์ชันต่อได้เลย!\n",
			g_pass, g_total);
	return (g_pass == g_total ? 0 : 1);
}
