/* ============================================================
**  test main สำหรับ ft_memcpy — เทียบกับ libc memcpy
**  compile:  gcc -Wall -Wextra -Werror main.c ft_memcpy.c -o test_memcpy
**  run:      ./test_memcpy   (Windows: test_memcpy.exe)
**  วิธีอ่าน: PASS = ค่าที่คัดลอกตรง libc + return ชี้ dst + ไม่เขียนเกิน n
** ============================================================ */
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);

static int	g_pass;
static int	g_total;

#define	BUF_SZ	128

/* เทียบ ft_memcpy กับ libc: copy src ลง dst_ft / dst_libc แล้วเทียบ n ตัวแรก
** เติม 0xAA ล่วงหน้า → เช็คด้วยว่าเขียนเกิน n หรือไม่ (ตัวหลัง n ต้องเป็น 0xAA อยู่)
** return ของ ft ต้องชี้ dst_ft พอดี */
static void	test_case(const void *src, size_t n, const char *label)
{
	unsigned char	dst_ft[BUF_SZ];
	unsigned char	dst_libc[BUF_SZ];
	void		*ret;
	size_t		i;
	int		ok;

	ret = NULL;
	for (i = 0; i < BUF_SZ; i++)
	{
		dst_ft[i] = 0xAA;
		dst_libc[i] = 0xAA;
	}
	memcpy(dst_libc, src, n);
	ret = ft_memcpy(dst_ft, src, n);

	ok = 1;
	if (ret != (void *)dst_ft)
	{
		ok = 0;
		printf("       ✗ return ไม่ชี้ dst เดิม\n");
	}
	if (memcmp(dst_ft, dst_libc, n) != 0)
	{
		ok = 0;
		printf("       ✗ ข้อมูล n=%zu ตัวแรกไม่ตรง libc\n", n);
	}
	for (i = n; i < BUF_SZ; i++)
	{
		if (dst_ft[i] != 0xAA)
		{
			ok = 0;
			printf("       ✗ เขียนเกิน n=%zu (index %zu กลายเป็น 0x%02X)\n",
				n, i, dst_ft[i]);
			break ;
		}
	}
	if (ok)
		g_pass++;
	g_total++;
	if (ok)
		printf("PASS  [%02d/%02d] %s\n", g_total, 11, label);
	else
		printf("FAIL  [%02d/%02d] %s\n", g_total, 11, label);
}

int	main(void)
{
	char		str1[] = "hello world";
	char		embedded[] = "ab\0cd";
	unsigned char	bin[16];
	unsigned char	big[100];
	size_t		i;

	printf("=== TEST ft_memcpy — เทียบกับ libc ===\n\n");

	printf("--- เคส string ---\n");
	test_case(str1, 11, "copy 'hello world' 11 bytes (รวม \\0)");
	test_case(str1, 5,  "copy 5 bytes แรก -> 'hello'");
	test_case(str1, 0,  "n=0 -> ไม่ควรทำอะไร");
	test_case(str1, 1,  "copy 1 byte -> 'h'");

	printf("\n--- เคส \\0 กลางทาง (memcpy ต้องไม่หยุดที่ \\0!) ---\n");
	test_case(embedded, 5, "'ab\\0cd' n=5 -> ครบ 5 bytes รวม \\0 กลาง");
	test_case(embedded, 3, "'ab\\0cd' n=3 -> 'ab\\0'");

	printf("\n--- เคส binary (byte 0x00-0xFF ไม่ใช่ string) ---\n");
	for (i = 0; i < 16; i++)
		bin[i] = (unsigned char)(i * 17);  /* 0,17,34,...,255 */
	test_case(bin, 16, "binary 16 bytes (มี 0xFF, 0x00 ปน)");
	test_case(bin, 7,  "binary 7 bytes แรก");
	test_case(bin, 0,  "binary n=0");

	printf("\n--- เคสยาว 100 ตัว ---\n");
	for (i = 0; i < 100; i++)
		big[i] = 'a' + (i % 26);
	test_case(big, 100, "100 ตัว a-z ซ้ำกัน");
	test_case(big, 99,  "99 ตัว (ไม่เต็ม buffer)");

	printf("\nผลรวม: %d/%d ผ่าน\n", g_pass, g_total);
	return (g_pass == g_total ? 0 : 1);
}
