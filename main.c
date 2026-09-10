/* ============================================================
**  test main สำหรับ ft_put*_fd (Part 2 — ชุดแรก)
**  compile:  gcc -Wall -Wextra -Werror main.c ft_putchar_fd.c \
**            ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c -o test_putfd
**  run:      ./test_putfd   (Windows: test_putfd.exe)
**  วิธีอ่าน: PASS = byte ที่เขียนผ่าน fd ตรงกับที่คาด (เทียบ byte ต่อ byte)
**  หลักการ: เปิดไฟล์ได้ fd → เรียก ft_*_fd → close → เปิดอ่าน → เทียบ
** ============================================================ */
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

static int	g_pass;
static int	g_total;
static int	g_cases;

static int	open_tmp(void)
{
	return (open("test_fd_out.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644));
}

static int	read_tmp(char *buf, int size)
{
	int	fd;
	int	n;

	fd = open("test_fd_out.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	n = read(fd, buf, size);
	close(fd);
	return (n);
}

static void	check(const char *label, const char *exp, int exp_len)
{
	char	buf[256];
	int		n;

	n = read_tmp(buf, sizeof(buf));
	g_total++;
	if (n == exp_len && (exp_len == 0 || memcmp(buf, exp, exp_len) == 0))
	{
		g_pass++;
		printf("PASS  [%02d/%02d] %-40s (len=%d)\n",
			g_total, g_cases, label, n);
	}
	else
		printf("FAIL  [%02d/%02d] %-40s (exp len=%d got len=%d)\n",
			g_total, g_cases, label, exp_len, n);
}

int	main(void)
{
	int	fd;

	g_cases = 17;
	printf("ft_put*_fd — เขียนผ่าน fd แล้วอ่านไฟล์เทียบ (%d cases)\n",
		g_cases);
	fd = open_tmp();
	ft_putchar_fd('A', fd);
	close(fd);
	check("putchar_fd 'A'", "A", 1);
	fd = open_tmp();
	ft_putchar_fd('\n', fd);
	close(fd);
	check("putchar_fd newline", "\n", 1);
	fd = open_tmp();
	ft_putchar_fd('\0', fd);
	close(fd);
	check("putchar_fd \\0 (ยังต้องเขียน 1 byte)", "\0", 1);
	fd = open_tmp();
	ft_putchar_fd((char)-1, fd);
	close(fd);
	check("putchar_fd byte 0xFF", "\xff", 1);
	fd = open_tmp();
	ft_putstr_fd("Hello", fd);
	close(fd);
	check("putstr_fd \"Hello\"", "Hello", 5);
	fd = open_tmp();
	ft_putstr_fd("", fd);
	close(fd);
	check("putstr_fd \"\" (ไม่เขียนอะไรเลย)", "", 0);
	fd = open_tmp();
	ft_putstr_fd("42 Bangkok", fd);
	close(fd);
	check("putstr_fd \"42 Bangkok\"", "42 Bangkok", 10);
	fd = open_tmp();
	ft_putendl_fd("Hello", fd);
	close(fd);
	check("putendl_fd \"Hello\" → Hello\\n", "Hello\n", 6);
	fd = open_tmp();
	ft_putendl_fd("", fd);
	close(fd);
	check("putendl_fd \"\" → แค่ \\n", "\n", 1);
	fd = open_tmp();
	ft_putnbr_fd(0, fd);
	close(fd);
	check("putnbr_fd 0", "0", 1);
	fd = open_tmp();
	ft_putnbr_fd(42, fd);
	close(fd);
	check("putnbr_fd 42", "42", 2);
	fd = open_tmp();
	ft_putnbr_fd(-42, fd);
	close(fd);
	check("putnbr_fd -42", "-42", 3);
	fd = open_tmp();
	ft_putnbr_fd(1000000, fd);
	close(fd);
	check("putnbr_fd 1000000", "1000000", 7);
	fd = open_tmp();
	ft_putnbr_fd(INT_MAX, fd);
	close(fd);
	check("putnbr_fd INT_MAX", "2147483647", 10);
	fd = open_tmp();
	ft_putnbr_fd(INT_MIN, fd);
	close(fd);
	check("putnbr_fd INT_MIN (trap!)", "-2147483648", 11);
	fd = open_tmp();
	ft_putnbr_fd(-1, fd);
	close(fd);
	check("putnbr_fd -1", "-1", 2);
	fd = open_tmp();
	ft_putstr_fd("abc", fd);
	ft_putendl_fd("def", fd);
	close(fd);
	check("putstr_fd+putendl_fd เขียนต่อ fd เดียว", "abcdef\n", 7);
	if (g_pass == g_total)
		printf("✅ PASSED %d/%d\n", g_pass, g_total);
	else
		printf("❌ FAILED %d/%d — ดู FAIL แล้วแก้ฟังก์ชันต่อได้เลย!\n",
			g_pass, g_total);
	return (g_pass == g_total ? 0 : 1);
}
