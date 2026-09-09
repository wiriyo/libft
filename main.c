/* ============================================================
**  test main สำหรับ ft_strnstr — เทียบกับ reference (glibc ไม่มี strnstr)
**  compile:  gcc -Wall -Wextra -Werror main.c ft_strnstr.c ft_strlen.c -o test_strnstr
**  run:      ./test_strnstr   (Windows: test_strnstr.exe)
**  วิธีอ่าน: PASS = คืน NULL ตรงกัน / เจอที่ offset ตรงกัน (เทียบตำแหน่ง pointer)
** ============================================================ */
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/* reference strnstr — glibc/WSL ไม่มี strnstr (เป็น BSD function)
** เขียนจำลองตาม man page เพื่อใช้เทียบใน test เท่านั้น (ไม่ใช่ code ส่ง!) */
static char	*ref_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

static int	g_pass;
static int	g_total;
static int	g_total_cases;

static void	test_case(const char *hay, const char *needle, size_t len,
			const char *label)
{
	char	*got;
	char	*exp;
	size_t	off_got;
	size_t	off_exp;
	int	ok;

	got = ft_strnstr(hay, needle, len);
	exp = ref_strnstr(hay, needle, len);
	g_total++;
	ok = 1;
	if ((got == NULL) != (exp == NULL))
	{
		ok = 0;
		printf("       ✗ คืน NULL ไม่ตรง: ft=%s libc=%s\n",
			got == NULL ? "NULL" : "found",
			exp == NULL ? "NULL" : "found");
	}
	else if (got != NULL)
	{
		off_got = (size_t)(got - hay);
		off_exp = (size_t)(exp - hay);
		if (off_got != off_exp)
		{
			ok = 0;
			printf("       ✗ เจอคนละตำแหน่ง: ft=offset %zu libc=offset %zu\n",
				off_got, off_exp);
		}
	}
	if (ok)
	{
		g_pass++;
		printf("PASS  [%02d/%02d] %s\n", g_total, g_total_cases, label);
	}
	else
		printf("FAIL  [%02d/%02d] %s\n", g_total, g_total_cases, label);
}

int	main(void)
{
	g_total_cases = 11;
	printf("ft_strnstr — เทียบกับ reference (%d cases)\n", g_total_cases);
	test_case("Hello World", "World", 20, "เจอกลาง len พอ");
	test_case("Hello World", "Hello", 20, "เจอที่ต้น");
	test_case("Hello World", "xyz", 20, "ไม่เจอเลย");
	test_case("Hello World", "", 20, "needle ว่าง → คืน haystack");
	test_case("Hello World", "World", 0, "len = 0 → NULL");
	test_case("Hello World", "World", 8, "needle เกิน len (6+5 > 8) → NULL");
	test_case("Hello World", "World", 11, "needle พอดีใน len (6+5 = 11)");
	test_case("abcabc", "abc", 4, "เจอที่ 0 แต่ตัวที่ 3 เกิน len");
	test_case("abc", "abcdef", 20, "needle ยาวกว่า haystack → NULL");
	test_case("abc\0def", "def", 20, "หลัง \\0 ของ haystack → NULL");
	test_case("Hello World", "World", 9, "len 9 (> 6+5? ไม่ 9 < 11) → NULL");
	if (g_pass == g_total)
		printf("✅ PASSED %d/%d\n", g_pass, g_total);
	else
		printf("❌ FAILED %d/%d — ดู FAIL แล้วแก้ฟังก์ชันต่อได้เลย!\n",
			g_pass, g_total);
	return (g_pass == g_total ? 0 : 1);
}
