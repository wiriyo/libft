/* ============================================================
**  test main สำหรับ ft_strtrim (Part 2 — ตัวที่ 7)
**  compile:  gcc -Wall -Wextra -Werror main.c ft_strtrim.c ft_strlen.c -o test_strtrim
**  run:      ./test_strtrim
**  วิธีอ่าน: PASS = สตริงที่ได้ตรงกับที่คาด + ต้นฉบับไม่ถูกแก้ + (เคส 12) ต้องเป็นก้อนใหม่
** ============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strtrim(char const *s1, char const *set);

static int	g_pass;
static int	g_total;
static int	g_cases;

static void	check(const char *label, char *got, const char *exp,
		char *s1, const char *s1_orig, char *set, const char *set_orig,
		int must_differ)
{
	int	ok;

	g_total++;
	ok = 1;
	if (got == NULL)
		ok = 0;
	else if (strcmp(got, exp) != 0)
		ok = 0;
	if (strcmp(s1, s1_orig) != 0 || strcmp(set, set_orig) != 0)
		ok = 0;
	if (must_differ && (got == s1 || got == set))
		ok = 0;
	if (ok)
	{
		g_pass++;
		printf("PASS  [%02d/%02d] %-32s -> \"%.40s\"\n",
			g_total, g_cases, label, got);
	}
	else if (got == NULL)
		printf("FAIL  [%02d/%02d] %-32s (ได้ NULL, คาด \"%s\")\n",
			g_total, g_cases, label, exp);
	else
		printf("FAIL  [%02d/%02d] %-32s (ได้ \"%.40s\" คาด \"%s\"%s%s)\n",
			g_total, g_cases, label, got, exp,
			(strcmp(s1, s1_orig) != 0 || strcmp(set, set_orig) != 0)
			? " [ต้นฉบับถูกแก้!]" : "",
			(must_differ && (got == s1 || got == set)) ? " [คืน pointer เดิม]" : "");
	if (got != NULL)
		free(got);
}

int	main(void)
{
	char	s1[] = "***Hello***";
	char	s2[] = "Hello";
	char	s3[] = "***Hello";
	char	s4[] = "Hello***";
	char	s5[] = "****";
	char	s6[] = "";
	char	s7[] = "Hello";
	char	s8[] = " \t\nHello\n\t ";
	char	s9[] = "*He*llo*";
	char	s10[] = "*";
	char	s11[] = "42Bangkok";
	char	s12[] = "Hello";
	char	set1[] = "*";
	char	set2[] = "*";
	char	set3[] = "*";
	char	set4[] = "*";
	char	set5[] = "*";
	char	set6[] = "*";
	char	set7[] = "";
	char	set8[] = " \t\n";
	char	set9[] = "*";
	char	set10[] = "*";
	char	set11[] = "42";
	char	set12[] = "*";

	g_cases = 12;
	printf("ft_strtrim — ตัดอักขระใน set จากหัว+ท้าย (%d cases)\n", g_cases);
	check("ตัดทั้งหัวและท้าย", ft_strtrim(s1, set1),
		"Hello", s1, "***Hello***", set1, "*", 0);
	check("ไม่ต้องตัดอะไร", ft_strtrim(s2, set2),
		"Hello", s2, "Hello", set2, "*", 0);
	check("ตัดหัวอย่างเดียว", ft_strtrim(s3, set3),
		"Hello", s3, "***Hello", set3, "*", 0);
	check("ตัดท้ายอย่างเดียว", ft_strtrim(s4, set4),
		"Hello", s4, "Hello***", set4, "*", 0);
	check("เป็น set หมดทั้งก้อน", ft_strtrim(s5, set5),
		"", s5, "****", set5, "*", 0);
	check("s1 ว่าง", ft_strtrim(s6, set6),
		"", s6, "", set6, "*", 0);
	check("set ว่าง (ไม่ตัดอะไร)", ft_strtrim(s7, set7),
		"Hello", s7, "Hello", set7, "", 0);
	check("whitespace หลายแบบ (space tab nl)", ft_strtrim(s8, set8),
		"Hello", s8, " \t\nHello\n\t ", set8, " \t\n", 0);
	check("ห้ามแตะตรงกลาง (*He*llo*)", ft_strtrim(s9, set9),
		"He*llo", s9, "*He*llo*", set9, "*", 0);
	check("ตัวเดียวและอยู่ใน set", ft_strtrim(s10, set10),
		"", s10, "*", set10, "*", 0);
	check("set หลายตัว (42Bangkok, set=42)", ft_strtrim(s11, set11),
		"Bangkok", s11, "42Bangkok", set11, "42", 0);
	check("ต้องเป็นก้อนใหม่ (ไม่ใช่ s1)", ft_strtrim(s12, set12),
		"Hello", s12, "Hello", set12, "*", 1);
	if (g_pass == g_total)
		printf("✅ PASSED %d/%d\n", g_pass, g_total);
	else
		printf("❌ FAILED %d/%d — ดู FAIL แล้วแก้ฟังก์ชันต่อได้เลย!\n",
			g_pass, g_total);
	return (g_pass == g_total ? 0 : 1);
}
