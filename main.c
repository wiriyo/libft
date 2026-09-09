/* ============================================================
**  test main สำหรับ ft_strlcpy — เทียบกับ libc strlcpy
**  compile:  gcc -Wall -Wextra -Werror main.c ft_strlcpy.c ft_strlen.c -o test_strlcpy
**  run:      ./test_strlcpy   (Windows: test_strlcpy.exe)
**  วิธีอ่าน: PASS = return ตรง libc + buffer ตรงกันทั้งก้อน (null-terminate + ไม่เขียนเกิน)
** ============================================================ */
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

static int	g_pass;
static int	g_total;
static int	g_total_cases;

#define	BUF_SZ	128

/* เติม 0xAA ล่วงหน้า → เรียก libc กับ ft บน buffer คนละอัน แล้วเทียบทั้ง 128 ตัว
** ครอบคลุม: return ต้องเท่ากัน + null-terminate ถูก + ไม่เขียนเกิน dstsize */
static void	test_case(const char *src, size_t dstsize, const char *label)
{
	char	dst_ft[BUF_SZ];
	char	dst_libc[BUF_SZ];
	size_t	ret_ft;
	size_t	ret_libc;
	size_t	i;
	int	ok;

	for (i = 0; i < BUF_SZ; i++)
	{
		dst_ft[i] = 0xAA;
		dst_libc[i] = 0xAA;
	}
	ret_libc = strlcpy(dst_libc, src, dstsize);
	ret_ft = ft_strlcpy(dst_ft, src, dstsize);
	g_total++;
	ok = 1;
	if (ret_ft != ret_libc)
	{
		ok = 0;
		printf("       ✗ return ผิด: ft=%zu libc=%zu (ต้อง = strlen(src) เสมอ!)\n",
			ret_ft, ret_libc);
	}
	if (memcmp(dst_ft, dst_libc, BUF_SZ) != 0)
	{
		ok = 0;
		printf("       ✗ buffer ไม่ตรง libc — null-terminate ผิด หรือเขียนเกิน dstsize?\n");
		for (i = 0; i < BUF_SZ; i++)
		{
			if (dst_ft[i] != dst_libc[i])
			{
				printf("         จุดแรกที่ต่าง: index %zu ft=0x%02X libc=0x%02X\n",
					i, (unsigned char)dst_ft[i],
					(unsigned char)dst_libc[i]);
				break ;
			}
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
	g_total_cases = 8;
	printf("ft_strlcpy — เทียบกับ libc strlcpy (%d cases)\n", g_total_cases);
	test_case("hello", 10, "dstsize 10 > len 5 (copy all)");
	test_case("hello", 6, "dstsize = len+1 (พอดี)");
	test_case("hello", 5, "dstsize = len (ตัด 1 ตัว + \\0)");
	test_case("hello", 3, "dstsize = 3 (ได้ 2 ตัว)");
	test_case("hello", 1, "dstsize = 1 (ได้แค่ \\0)");
	test_case("hello", 0, "dstsize = 0 (ห้ามแตะ dst!)");
	test_case("", 5, "src ว่าง");
	test_case("", 0, "src ว่าง + dstsize 0");
	if (g_pass == g_total)
		printf("✅ PASSED %d/%d\n", g_pass, g_total);
	else
		printf("❌ FAILED %d/%d — ดู FAIL แล้วแก้ฟังก์ชันต่อได้เลย!\n",
			g_pass, g_total);
	return (g_pass == g_total ? 0 : 1);
}
