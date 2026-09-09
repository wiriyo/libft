/* ============================================================
**  test main สำหรับ ft_calloc — เทียบกับ libc calloc
**  compile:  gcc -Wall -Wextra -Werror main.c ft_calloc.c ft_bzero.c -o test_calloc
**  run:      ./test_calloc   (Windows: test_calloc.exe)
**  วิธีอ่าน: PASS = ได้ pointer ไม่ NULL + ทุก byte เป็น 0 ตรง libc
** ============================================================ */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size);

static int	g_pass;
static int	g_total;
static int	g_total_cases;

/* เทียบ ft_calloc กับ libc: จอง count*size เท่ากัน แล้วเช็ค
** 1. ถ้า libc ได้ pointer (ไม่ NULL) → ft ต้องได้ด้วย
** 2. ทุก byte ในช่วง count*size ต้องตรงกัน (libc zero ให้ → ft ต้อง zero ด้วย)
** 3. กรณี count*size = 0: glibc คืน pointer ที่ free ได้ → ต้องไม่ NULL เหมือนกัน */
static void	test_case(size_t count, size_t size, const char *label)
{
	unsigned char	*got;
	unsigned char	*exp;
	size_t		n;
	int		ok;

	n = count * size;
	got = ft_calloc(count, size);
	exp = calloc(count, size);
	g_total++;
	ok = 1;
	if (exp != NULL && got == NULL)
	{
		ok = 0;
		printf("       ✗ ft คืน NULL แต่ libc คืน pointer (จอง %zu bytes)\n", n);
	}
	if (exp == NULL && got != NULL)
	{
		ok = 0;
		printf("       ✗ ft คืน pointer แต่ libc คืน NULL — จองเกินที่ควร?\n");
	}
	if (ok && n > 0 && memcmp(got, exp, n) != 0)
	{
		ok = 0;
		printf("       ✗ มี byte ที่ไม่ตรง libc — ลืม zero หรือ zero ไม่ครบ?\n");
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
	g_total_cases = 7;
	printf("ft_calloc — เทียบกับ libc calloc (%d cases)\n", g_total_cases);
	test_case(5, sizeof(int), "5 x int (20 bytes)");
	test_case(1, 1, "1 x 1 byte");
	test_case(10, sizeof(char), "10 chars");
	test_case(2, sizeof(double), "2 x double (16 bytes)");
	test_case(0, 10, "count = 0 (ต้องได้ pointer)");
	test_case(10, 0, "size = 0 (ต้องได้ pointer)");
	test_case(100, 1000, "100 x 1000 (100k bytes)");
	if (g_pass == g_total)
		printf("✅ PASSED %d/%d\n", g_pass, g_total);
	else
		printf("❌ FAILED %d/%d — ดูเคส FAIL แล้วแก้ฟังก์ชันต่อได้เลย!\n",
			g_pass, g_total);
	return (g_pass == g_total ? 0 : 1);
}
