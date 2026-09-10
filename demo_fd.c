/* ============================================================
**  demo_fd.c — "เห็น" เลขช่องทาง (fd) ด้วยตาตัวเอง
**  compile: gcc demo_fd.c -o demo_fd && ./demo_fd
**  (ตัวนี้ไม่เกี่ยวกับ libft — แค่โชว์ว่า fd คือเลขอะไร มาจากไหน)
** ============================================================ */
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	fd1;
	int	fd2;

	printf("ค่าคงที่ที่มีให้ทุกโปรแกรม: STDIN=%d STDOUT=%d STDERR=%d\n",
		STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
	fd1 = open("demo_a.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	printf("open(\"demo_a.txt\")                  -> fd = %d\n", fd1);
	fd2 = open("demo_b.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	printf("open(\"demo_b.txt\")                  -> fd = %d\n", fd2);
	printf("open(ไฟล์ที่ไม่มีอยู่จริง)              -> fd = %d  (-1 = ล้มเหลว)\n",
		open("no_such_file_xyz.txt", O_RDONLY));
	close(fd1);
	printf("close(fd=%d) เรียบร้อย...\n", fd1);
	fd1 = open("demo_c.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	printf("open(\"demo_c.txt\")                  -> fd = %d  (เลขที่ว่าง ถูกดึงกลับมาใช้!)\n",
		fd1);
	close(fd1);
	close(fd2);
	return (0);
}
