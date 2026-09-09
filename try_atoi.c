/* ============================================================
**  scratch สำหรับลองทีละขั้นตอน (ไม่เกี่ยวกับงานส่ง moulinette!)
**  วิธีใช้: เติม code ทีละขั้น A → B → C → D แล้วรันดูผล
**  compile:  gcc try_atoi.c -o try_atoi && ./try_atoi
** ============================================================ */
#include <stdio.h>

int	main(void)
{
	char	*s = "   \t -42abc";
	int	i;
	int	sign;
	long result;

	i = 0;
	sign = 1;
	result = 0;
	/* ===== ขั้น A: ข้าม whitespace =====
	** ลองเติม: while (s[i] เป็น whitespace) i++;
	** whitespace = ' ', '\t', '\n', '\v', '\f', '\r'
	** แล้วเช็คว่า i หยุดที่ตัวแรกที่ไม่ใช่ whitespace (ควรเป็น '-' ที่ index ?) */
	/* TODO: เติม loop ข้าม whitespace ตรงนี้ */
	while ( s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\f' || s[i] == '\r' || s[i] == '\v')
	{
		i++;
	}

	printf("A: หลังข้าม whitespace -> s[%d] = '%c'\n", i, s[i]);

	/* ===== ขั้น B: เช็คเครื่องหมาย =====
	** ถ้า s[i] == '+' → i++
	** ถ้า s[i] == '-' → sign = -1; i++
	** แล้วเช็คว่า i ขยับถูกไหม (ควรชี้ '4') */
	/* TODO: เติมเช็คเครื่องหมายตรงนี้ */
	if (s[i] == '-')
		sign = -1;
	printf("B: sign = %d, ตอนนี้ s[%d] = '%c'\n", sign, i, s[i]);
	i++;
	/* ===== ขั้น C: เก็บเลขทีละหลัก =====
	** ลองเติม: while (s[i] เป็นเลข '0'-'9')
	**              result = result * 10 + (s[i] - '0');
	**              i++;
	** แล้ว printf result ระหว่างทาง (ควรได้ 42 แล้วหยุดที่ 'a') */
	/* TODO: เติม loop เก็บเลขตรงนี้ (ประกาศ result = 0 ก่อน) */
	while ( '0' <= s[i] && s[i] <= '9' )
	{
		result = result *10 + (s[i]- '0');
		i++;
	}
	printf("%ld\n",result);
	/* ===== ขั้น D: ประกอบผล =====
	** result * sign → ลอง printf ผลสุดท้าย (ควรได้ -42) */
	result = result * sign;
	printf("%ld\n",result);
	return (0);
}
