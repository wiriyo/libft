/* ============================================================
**  test main สำหรับ ft_memchr — เทียบกับ libc memchr (เทียบ offset)
**  compile:  gcc -Wall -Wextra -Werror main.c ft_memchr.c -o test
**  run:      ./test   (Windows: test.exe)
**  วิธีอ่าน: PASS = offset ที่เจอตรงกับ libc (หรือ NULL ตรงกัน)
** ============================================================ */
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n);

static int	g_pass;
static int	g_total;

/* เทียบผล: ทั้งคู่ NULL หรือ offset จาก base เท่ากัน */
static void	test_pair(const void *s, int c, size_t n)
{
	const unsigned char	*base;
	unsigned char		*libc_r;
	unsigned char		*ft_r;
	long			libc_off;
	long			ft_off;

	base = (const unsigned char *)s;
	libc_r = (unsigned char *)memchr(s, c, n);
	ft_r = (unsigned char *)ft_memchr(s, c, n);
	libc_off = libc_r ? (long)(libc_r - base) : -1;
	ft_off = ft_r ? (long)(ft_r - base) : -1;
	g_total++;
	if (libc_off == ft_off)
	{
		g_pass++;
		if (libc_off == -1)
			printf("PASS  memchr(..., %d, %zu) → NULL\n", c, n);
		else
			printf("PASS  memchr(..., %d, %zu) → offset %ld\n", c, n, libc_off);
	}
	else
	{
		printf("FAIL  memchr(..., %d, %zu)  libc=%ld  ft=%ld\n",
			c, n, libc_off, ft_off);
	}
}

/* เคส string ธรรมดา — c เป็น int */
static const struct s_case
{
	const char	*s;
	int		c;
	size_t		n;
}	g_cases[] = {
	{"hello", 'l', 5},        /* 'l' ตัวแรกที่ offset 2 */
	{"hello", 'h', 5},        /* offset 0 */
	{"hello", 'o', 5},        /* offset 4 */
	{"hello", 'x', 5},        /* ไม่มี → NULL */
	{"hello", '\0', 6},       /* n รวม \0 → เจอ offset 5 */
	{"hello", '\0', 5},       /* n ไม่ถึง \0 → NULL */
	{"hello", 'l', 0},        /* n=0 → NULL เสมอ */
	{"hello", 'e', 1},        /* n=1 ดูแค่ 'h' → NULL (e อยู่ index 1) */
	{"ab\0cd", 'c', 5},       /* ★ ข้าม \0 ได้ → เจอ offset 3 (ไม่หยุดที่ \0!) */
	{"ab\0cd", '\0', 5},      /* เจอ \0 กลาง → offset 2 */
	{"ab\0cd", 'z', 5},       /* ไม่มี → NULL */
	{"a", 'a', 1},            /* offset 0 */
	{"", '\0', 0},            /* ว่าง + n=0 → NULL */
	{"", '\0', 1},            /* ว่างมีแต่ \0, n=1 → offset 0 */
};

int	main(void)
{
	size_t	i;
	char	hi[3];
	char	big[101];

	/* --- เคส string --- */
	for (i = 0; i < sizeof(g_cases) / sizeof(g_cases[0]); i++)
	{
		printf("memchr(\"%s\", %d, %zu) → ", g_cases[i].s,
			g_cases[i].c, g_cases[i].n);
		test_pair(g_cases[i].s, g_cases[i].c, g_cases[i].n);
	}

	/* --- เคส unsigned byte (0xFF = 255 ไม่ใช่ -1) --- */
	hi[0] = (char)0xFF;
	hi[1] = '\0';
	hi[2] = 'A';
	printf("memchr([0xFF,0,'A'], 0xFF, 3) → ");
	test_pair(hi, 0xFF, 3);        /* เรียก c=255 → ต้องเจอ offset 0 */
	printf("memchr([0xFF,0,'A'], 0x00, 3) → ");
	test_pair(hi, 0x00, 3);        /* offset 1 */
	printf("memchr([0xFF,0,'A'], 'A', 3) → ");
	test_pair(hi, 'A', 3);         /* offset 2 */
	printf("memchr([0xFF,0,'A'], 'B', 3) → ");
	test_pair(hi, 'B', 3);         /* NULL */

	/* --- เคสยาว 100 ตัว --- */
	for (i = 0; i < 100; i++)
		big[i] = 'a' + (i % 26);
	big[100] = '\0';
	printf("memchr(100-char, ตัวสุดท้าย, 100) → ");
	test_pair(big, big[99], 100);  /* offset 99 */
	printf("memchr(100-char, 'Z', 100) → ");
	test_pair(big, 'Z', 100);      /* NULL */

	printf("\nผลรวม: %d/%d ผ่าน\n", g_pass, g_total);
	return (g_pass == g_total ? 0 : 1);
}
