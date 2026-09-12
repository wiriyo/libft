/* main.c — test spec: ft_itoa (ไฟล์ทดสอบ ห้ามส่ง! ลบก่อน submit)
 * รัน: gcc -Wall -Wextra -Werror ft_itoa.c main.c -o test && ./test */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_itoa(int n);

static int g_fail = 0;
static int g_idx = 0;

static void check(int n, char *label)
{
 char ref[32];
 char *got;

 snprintf(ref, sizeof(ref), "%d", n);
 got = ft_itoa(n);
 g_idx++;
 if (got == NULL)
 {
  printf("FAIL [%02d] %-24s n=%-11d expected \"%s\" got NULL\n",
   g_idx, label, n, ref);
  g_fail++;
  return ;
 }
 if (strcmp(got, ref) != 0)
 {
  printf("FAIL [%02d] %-24s n=%-11d expected \"%s\" got \"%s\"\n",
   g_idx, label, n, ref, got);
  g_fail++;
 }
 else
  printf("PASS [%02d] %-24s n=%-11d -> \"%s\"\n", g_idx, label, n, got);
 free(got);
}

int main(void)
{
 char *tmp;

 printf("=== ft_itoa test spec (reference = snprintf) ===\n");
 check(0, "zero");
 check(7, "1 digit");
 check(-7, "1 digit negative");
 check(10, "2 digits");
 check(-10, "2 digits negative");
 check(42, "2 digits (answer)");
 check(-42, "2 digits negative");
 check(-1, "minus one");
 check(100, "trailing zero");
 check(-100, "trailing zero negative");
 check(12345, "5 digits");
 check(-1234567890, "10 digits negative");
 check(INT_MAX, "INT_MAX");
 check(-2147483647, "INT_MIN + 1");
 check(INT_MIN, "INT_MIN (trap!)");
 printf("--- bonus: ต้องเป็น heap เขียนได้ + free ได้ ---\n");
 g_idx++;
 tmp = ft_itoa(0);
 if (tmp == NULL)
  printf("FAIL [%02d] heap writable + freeable : NULL\n", g_idx);
 else
 {
  tmp[0] = 'X';
  tmp[0] = '0';
  free(tmp);
  printf("PASS [%02d] heap writable + freeable (ไม่ใช่ literal)\n", g_idx);
 }
 printf("=== summary: %d cases, FAIL %d ===\n", g_idx, g_fail);
 return (g_fail != 0);
}
