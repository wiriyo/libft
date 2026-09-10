/* ============================================================
**  try_trim.c — ไฟล์ SCRATCH สำหรับทดลอง (เหมือน try_atoi.c)
**  ⚠️ ไม่ต้องส่ง! แค่หัด/ดูค่า — อย่าลืมลบออกจากโฟลเดอร์ก่อนส่ง 13 ก.ย.
**  compile:  gcc -Wall -Wextra -Werror try_trim.c -o try_trim && ./try_trim
**
**  เป้าหมายของไฟล์นี้: "เห็นค่า start กับ end" ของทุกเคส ก่อนเอาไปใช้จริง
**  ตอนนี้ยังเป็นโครง — พี่เติม logic ใน TODO เอง แล้วรันดูค่าที่พิมพ์ออกมา
** ============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* แสดงสตริงโดยเห็น \n \t ชัดๆ (แค่ง่ายๆ ตอน debug) */
static void	print_escaped(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			printf("\\n");
		else if (s[i] == '\t')
			printf("\\t");
		else
			printf("%c", s[i]);
		i++;
	}
}

/* ============================================================
**  in_set — helper (โครงเปล่า)
**  หน้าที่: เช็คว่าตัวอักษร c อยู่ใน "ชุด" set ไหม
**  return: 1 = อยู่ใน set / 0 = ไม่อยู่
**  ⚠️ วางไว้ "บนสุด" ของไฟล์ (ก่อน ft_strtrim) และใส่ static
**  ⚠️ ไม่ต้องใส่ prototype ใน libft.h (เป็น helper ภายในไฟล์)
** ============================================================ */
static int in_set(char c, const char *set)
{
 size_t i;

	i = 0;
	while(set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
 return (0);
}

/* ------------------------------------------------------------
**  ส่วนที่พี่กำลังหัด: หา start (หัว) และ end (ท้าย)
**  หมายเหตุ: ไฟล์นี้ "ไม่ malloc" — แค่คำนวณ + printf ให้เห็นค่าก่อน
** ------------------------------------------------------------ */
void	t_trim_debug(const char *s1, const char *set)
{
	size_t	len1;
	size_t	len2;
	size_t	start;
	size_t	end;
	size_t	i;

	len1 = strlen(s1);
	len2 = strlen(set);
	i = 0;
	/* ====== TODO 1: หา start ======
	** เดินจากซ้าย (index 0) ไปเรื่อยๆ ข้ามอักขระที่ "อยู่ใน set"
	** หยุดที่ตัวแรกที่ "ไม่อยู่ใน set" → นั่นคือ start
	** 💡 โจทย์ย่อย: เช็คยังไงว่า "ตัวอักษร c อยู่ใน set ไหม"?
	**    → ต้องวนเทียบกับ "ทุกตัว" ใน set (ไม่ใช่เทียบแค่ set[0]!)
	**    → ทำเป็น helper ได้ เช่น  static int in_set(char c, const char *set)
	*/
	start = 0;
	while (s1[i] && in_set(s1[i],set))
		i++;
	start = i;
	/* ====== TODO 2: หา end ======
	** เดินถอยจากตัวสุดท้ายของ s1 → หยุดที่ตัวแรกที่ "ไม่อยู่ใน set"
	** สองแบบที่นิยม (เลือกเอง แล้วให้สอดคล้องตอนคำนวณความยาว):
	**    A) end = index ของตัวสุดท้ายที่ "เก็บ"        → ความยาว = end - start + 1
	**    B) end = หนึ่งตำแหน่ง "เลย" ตัวสุดท้ายที่เก็บ  → ความยาว = end - start
	** ⚠️ ระวัง!: เงื่อนไขต้องเป็น  i > 0  (ไม่ใช่  i >= 0 — size_t จริงเสมอ!)
	** ⚠️ ระวัง!: กรณีไม่เหลืออะไรเลย (เช่น "****" , set="*") อย่าให้ค่าติดลบ
	*/
	end = len1;
	while (end > start && in_set(s1[end-1],set))
		end--;
	/* ====== จุดสำคัญของการทดลอง: ให้เห็นค่า ====== */
	printf("s1=\"");
	print_escaped(s1);
	printf("\"  set=\"");
	print_escaped(set);
	printf("\"\n");
	printf("   len1=%zu  len2=%zu   ->   start=%zu   end=%zu\n",
		len1, len2, start, end);
}

/* ------------------------------------------------------------
**  main: ลองทีละเคส (ค่าที่ "ถูก" ดูได้จากโจทก์/spec)
** ------------------------------------------------------------ */
int	main(void)
{
	printf("== ทดลอง ft_strtrim: ดูค่า start / end ==\n\n");
	t_trim_debug("***Hello***", "*");
	t_trim_debug("Hello", "*");
	t_trim_debug("***Hello", "*");
	t_trim_debug("Hello***", "*");
	t_trim_debug("****", "*");
	t_trim_debug("", "*");
	t_trim_debug("Hello", "");
	t_trim_debug(" \t\nHello\n\t ", " \t\n");
	t_trim_debug("*He*llo*", "*");
	t_trim_debug("42Bangkok", "42");
	printf("\n(เทียบผลกับตารางในโจทก์ — ถ้า start/end ถูกทุกเคส ค่อยก็อปไปใช้ใน ft_strtrim.c)\n");
	return (0);
}
