/* ============================================================
**  test main สำหรับ ft_strncmp — เทียบกับ libc strncmp ตรงๆ
**  compile:  gcc -Wall -Wextra -Werror main.c ft_strncmp.c -o test
**  run:      ./test   (Windows: test.exe)
**  วิธีอ่าน: PASS = พี่กับ libc ให้เครื่องหมายเดียวกัน (42 ดูแค่ sign)
** ============================================================ */
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

/* 42/libc รับประกันแค่เครื่องหมาย — เทียบ sign ไม่เทียบค่าเป๊ะ */
static int	sign(int v)
{
	if (v < 0)
		return (-1);
	if (v > 0)
		return (1);
	return (0);
}

static int	g_pass;
static int	g_total;

static void	test_pair(const char *s1, const char *s2, size_t n)
{
	int	libc;
	int	ft;

	libc = sign(strncmp(s1, s2, n));
	ft = sign(ft_strncmp(s1, s2, n));
	g_total++;
	if (libc == ft)
	{
		g_pass++;
		printf("PASS  [%zu] ft == libc == %+d\n", n, ft);
	}
	else
	{
		printf("FAIL  [%zu] libc=%+d  ft=%+d\n", n, libc, ft);
	}
}

/* เทสต์เคส: {s1, s2, n} */
static const struct s_case
{
	const char	*s1;
	const char	*s2;
	size_t		n;
}	g_cases[] = {
	{"cat", "dog", 3},          /* ต่างที่ index 0 */
	{"cat", "car", 3},          /* ต่างที่ index 2 */
	{"cat", "cat", 3},          /* เท่ากันครบ */
	{"cat", "catch", 6},        /* s1 จบก่อน (\0 vs 'c') */
	{"catch", "cat", 6},        /* กลับฝั่ง ('c' vs \0) */
	{"cat", "dog", 0},          /* n = 0 → 0 เสมอ */
	{"cat", "dog", 1},          /* n ตัดก่อนถึงตัวต่าง */
	{"abc", "abd", 2},          /* n ตัดก่อน d → เท่ากัน */
	{"abc", "abd", 3},          /* n ครบ → เห็น d */
	{"", "", 5},                /* ว่างทั้งคู่ */
	{"", "a", 5},               /* ว่าง vs มี */
	{"a", "", 5},               /* มี vs ว่าง */
	{"hello", "hello world", 5}, /* n = ความยาวพอดี */
	{"hello", "hello world", 6}, /* n เลย \0 ไป 1 */
	{"same", "same", 0},        /* n=0 แม้ string เท่ากัน */
};

int	main(void)
{
	size_t	i;
	char	hi1[3];
	char	hi2[3];
	char	long_a[101];
	char	long_b[101];

	/* --- เคสธรรมดา --- */
	for (i = 0; i < sizeof(g_cases) / sizeof(g_cases[0]); i++)
	{
		printf("strncmp(\"%s\", \"%s\", %zu) → ", g_cases[i].s1,
			g_cases[i].s2, g_cases[i].n);
		test_pair(g_cases[i].s1, g_cases[i].s2, g_cases[i].n);
	}

	/* --- เคส unsigned char trap (non-ASCII) ---
	**   ตัวแรก: byte 0xFF (unsigned = 255, signed = -1)
	**   ตัวที่สอง: byte 0x00
	**   libc เทียบ unsigned → 0xFF > 0x00 → ค่าบวก
	**   ถ้าพี่เทียบ char ธรรมดา → -1 vs 0 → ค่าลบ → FAIL ตรงนี้! */
	hi1[0] = (char)0xFF;  hi1[1] = 'A'; hi1[2] = '\0';
	hi2[0] = (char)0x00;  hi2[1] = 'B'; hi2[2] = '\0';
	printf("strncmp(high-byte, zero-byte, 2) → ");
	test_pair(hi1, hi2, 2);

	/* --- เคสยาว 100 ตัวเท่ากัน --- */
	for (i = 0; i < 100; i++)
	{
		long_a[i] = 'a' + (i % 26);
		long_b[i] = long_a[i];
	}
	long_a[100] = '\0';
	long_b[100] = '\0';
	printf("strncmp(100-identical, 100) → ");
	test_pair(long_a, long_b, 100);

	printf("\nผลรวม: %d/%d ผ่าน\n", g_pass, g_total);
	return (g_pass == g_total ? 0 : 1);
}
