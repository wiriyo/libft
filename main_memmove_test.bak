/* ============================================================
**  test main สำหรับ ft_memmove — เทียบกับ libc memmove
**  compile:  gcc -Wall -Wextra -Werror main.c ft_memmove.c -o test_memmove
**  run:      ./test_memmove   (Windows: test_memmove.exe)
**  วิธีอ่าน: PASS = ผลลัพธ์ตรง libc ทั้ง buffer + return ชี้ dst
** ============================================================ */
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n);

static int	g_pass;
static int	g_total;
static int	g_total_cases;

#define	BUF_SZ	128

/* เติม pattern ไม่ซ้ำระยะสั้น (i*7+3 mod 251) — ถ้าข้อมูลซ้ำกัน
** overlap พังจะไม่ถูกจับได้ จึงต้องใช้ pattern ที่ไม่ซ้ำ */
static void	fill_pattern(unsigned char *buf)
{
	size_t	i;

	for (i = 0; i < BUF_SZ; i++)
		buf[i] = (unsigned char)((i * 7 + 3) % 251);
}

/* ====== เคสที่ 1: copy ระหว่าง buffer คนละอัน (ไม่ overlap) ====== */
static void	test_copy(const unsigned char *src, size_t src_sz,
			const char *label)
{
	unsigned char	dst_ft[BUF_SZ];
	unsigned char	dst_libc[BUF_SZ];
	size_t		n;
	size_t		i;
	int		ok;

	n = src_sz;
	for (i = 0; i < BUF_SZ; i++)
	{
		dst_ft[i] = 0xAA;
		dst_libc[i] = 0xAA;
	}
	memmove(dst_libc, src, n);
	if (ft_memmove(dst_ft, src, n) != (void *)dst_ft)
	{
		printf("FAIL  [%02d/%02d] %s (return ไม่ชี้ dst)\n",
			g_total + 1, g_total_cases, label);
		g_total++;
		return ;
	}
	ok = memcmp(dst_ft, dst_libc, n) == 0;
	for (i = n; i < BUF_SZ; i++)
	{
		if (dst_ft[i] != 0xAA)
		{
			ok = 0;
			printf("       ✗ เขียนเกิน n=%zu (index %zu)\n", n, i);
			break ;
		}
	}
	g_total++;
	if (ok)
	{
		g_pass++;
		printf("PASS  [%02d/%02d] %s\n", g_total, g_total_cases, label);
	}
	else
		printf("FAIL  [%02d/%02d] %s\n", g_total, g_total_cases, label);
}

/* ====== เคสที่ 2: overlap ใน buffer เดียว ======
** buffer เต็มด้วย pattern -> ft_memmove(buf+dst_off, buf+src_off, n)
** เทียบผลกับ libc memmove ทั้ง 128 ตัว (buffer โดนเลื่อน อาจกระทบรอบข้าง) */
static void	test_overlap(size_t dst_off, size_t src_off, size_t n,
			const char *label)
{
	unsigned char	ft_buf[BUF_SZ];
	unsigned char	libc_buf[BUF_SZ];
	size_t		i;
	int		ok;

	fill_pattern(ft_buf);
	fill_pattern(libc_buf);
	if (ft_memmove(ft_buf + dst_off, ft_buf + src_off, n)
		!= (void *)(ft_buf + dst_off))
	{
		printf("FAIL  [%02d/%02d] %s (return ไม่ชี้ dst)\n",
			g_total + 1, g_total_cases, label);
		g_total++;
		return ;
	}
	memmove(libc_buf + dst_off, libc_buf + src_off, n);
	ok = memcmp(ft_buf, libc_buf, BUF_SZ) == 0;
	g_total++;
	if (ok)
	{
		g_pass++;
		printf("PASS  [%02d/%02d] %s\n", g_total, g_total_cases, label);
	}
	else
	{
		printf("FAIL  [%02d/%02d] %s\n", g_total, g_total_cases, label);
		for (i = 0; i < BUF_SZ; i++)
		{
			if (ft_buf[i] != libc_buf[i])
			{
				printf("       ✗ ตำแหน่งแรกที่ต่าง = index %zu"
					" (ft=0x%02X libc=0x%02X)\n",
					i, ft_buf[i], libc_buf[i]);
				break ;
			}
		}
	}
}

int	main(void)
{
	char		str[] = "hello world";
	unsigned char	bin[16];
	size_t		i;

	g_total_cases = 15;

	printf("=== TEST ft_memmove — เทียบกับ libc ===\n\n");

	printf("--- เคสไม่ overlap (buffer คนละอัน) ---\n");
	test_copy((unsigned char *)str, 11, "copy 'hello world' 11 bytes");
	test_copy((unsigned char *)str, 5, "copy 5 bytes แรก -> 'hello'");
	test_copy((unsigned char *)str, 0, "n=0 -> ไม่ทำอะไร");
	for (i = 0; i < 16; i++)
		bin[i] = (unsigned char)(i * 17);
	test_copy(bin, 16, "binary 16 bytes");

	printf("\n--- เคส overlap: ขยับขวา (dst อยู่หลัง src — ต้องวนถอยหลัง!) ---\n");
	test_overlap(3, 0, 11, "ขยับ 'hello world' ขวา 3 ช่อง (dst=3,src=0,n=11)");
	test_overlap(1, 0, 5,  "ขยับ 'hello' ขวา 1 ช่อง (dst=1,src=0,n=5) ★คลาสสิก");
	test_overlap(6, 4, 8,  "เหลื่อมบางส่วน: ขวา 2 (dst=6,src=4,n=8)");
	test_overlap(1, 0, 64, "ขยับขวา 1 ช่อง ก้อนใหญ่ 64 bytes");

	printf("\n--- เคส overlap: ขยับซ้าย (dst อยู่ก่อน src — วนหน้าหลังได้) ---\n");
	test_overlap(0, 3, 11, "ขยับ 'hello world' ซ้าย 3 ช่อง (dst=0,src=3,n=11)");
	test_overlap(0, 1, 5,  "ขยับ 'hello' ซ้าย 1 ช่อง (dst=0,src=1,n=5) ★คลาสสิก");
	test_overlap(2, 8, 10, "เหลื่อมบางส่วน: ซ้าย 6 (dst=2,src=8,n=10)");
	test_overlap(0, 1, 64, "ขยับซ้าย 1 ช่อง ก้อนใหญ่ 64 bytes");

	printf("\n--- เคส edge ---\n");
	test_overlap(5, 5, 10, "dst == src (dst=5,src=5) -> ไม่ควรเพี้ยน");
	test_overlap(5, 0, 0,  "n=0 แม้ตำแหน่งต่าง -> ไม่ทำอะไร");
	test_overlap(0, 1, 127, "ขยับซ้าย 1 เกือบเต็ม buffer (127 bytes)");

	printf("\nผลรวม: %d/%d ผ่าน\n", g_pass, g_total);
	return (g_pass == g_total ? 0 : 1);
}
