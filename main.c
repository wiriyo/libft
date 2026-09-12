/* main.c — test spec: ft_strmapi  (ไฟล์เทสต์ ห้ามส่ง! ลบก่อน submit)
 * รัน: gcc -Wall -Wextra -Werror ft_strmapi.c main.c -o test && ./test
 *      (ถ้าอิมพลีเมนต์เรียก ft_strlen ให้เพิ่ม ft_strlen.c เข้าไปด้วย) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

static int	g_fail;
static int	g_idx;
static int	g_calls;

/* f: ตัวพิมพ์ใหญ่ (ทดสอบ map พื้นฐาน) */
static char	f_up(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/* f: บวก index (พิสูจน์ว่าส่ง index มาถูกช่อง) */
static char	f_add(unsigned int i, char c)
{
	return ((char)((unsigned char)c + i));
}

/* f: นับจำนวนครั้งที่ถูกเรียก */
static char	f_cnt(unsigned int i, char c)
{
	(void)i;
	g_calls++;
	return (c);
}

static void	report(int ok, const char *label)
{
	g_idx++;
	if (ok)
		printf("PASS [%02d/09] %s\n", g_idx, label);
	else
	{
		printf("FAIL [%02d/09] %s\n", g_idx, label);
		g_fail++;
	}
}

int main(void)
{
	char	*got;
	char	src[8];

	got = ft_strmapi("hello", f_up);
	report(got && !strcmp(got, "HELLO"), "lower->UPPER  \"hello\" -> \"HELLO\"");
	free(got);

	got = ft_strmapi("abc", f_add);
	report(got && !strcmp(got, "ace"), "index ส่งถูก:  \"abc\" -> \"ace\"");
	free(got);

	got = ft_strmapi("aaaa", f_add);
	report(got && !strcmp(got, "abcd"), "\"aaaa\" -> \"abcd\"");
	free(got);

	got = ft_strmapi("", f_up);
	report(got && got[0] == '\0', "empty -> \"\"");
	free(got);

	strcpy(src, "abc");
	got = ft_strmapi(src, f_up);
	report(got && !strcmp(got, "ABC") && !strcmp(src, "abc"),
		"ไม่แก้ต้นฉบับ (not in place)");
	free(got);

	got = ft_strmapi("abc", f_cnt);
	report(got && g_calls == 3, "เรียก f ครบ len ครั้ง (3)");
	free(got);

	got = ft_strmapi("ab", f_up);
	report(got && got[0] == 'A' && got[1] == 'B' && got[2] == '\0',
		"ปิด '\\0' ท้ายสตริง");
	free(got);

	report(ft_strmapi(NULL, f_up) == NULL, "NULL -> NULL (defensive)");

	got = ft_strmapi("x", f_up);
	report(got && got[0] == 'X' && got[1] == '\0', "สตริงยาว 1 ตัว");
	free(got);

	printf("=== %d cases, %d FAIL ===\n", g_idx, g_fail);
	return (g_fail != 0);
}
