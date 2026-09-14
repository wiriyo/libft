*This project has been created as part of the 42 curriculum by `awiriyok`.*

# libft

## Description

Libft คือโปรเจกต์แรกของหลักสูตร 42 — สร้างไลบรารีฟังก์ชันภาษา C ขึ้นเอง เพื่อใช้ซ้ำได้ตลอดหลักสูตร *(Your very own C library: a reimplementation of a subset of the standard library, plus extra utility and linked-list functions.)*

ประกอบด้วย 3 ส่วน รวม 43 ฟังก์ชัน:

- **Part 1 — Libc functions** (23 ตัว) — ฟังก์ชันมาตรฐานจาก libc
- **Part 2 — Additional functions** (11 ตัว) — ฟังก์ชันเสริมที่ libc ไม่มี
- **Part 3 — Linked list** (9 ตัว) — จัดการโครงสร้าง linked list (`t_list`)

## Library Functions

### Part 1 — Libc functions

| Function | Description |
|----------|-------------|
| `ft_memset` | เติม `len` ไบต์แรกของ `b` ด้วยค่า `c` (มองเป็น unsigned char) แล้ว**คืน `b`** *(Fill first `len` bytes of `b` with `c` as unsigned char; returns `b`)* |
| `ft_bzero` | เติม `n` ไบต์แรกของ `s` ด้วย `0` — **ไม่คืนค่า** *(Zero first `n` bytes of `s`; no return)* |
| `ft_memcpy` | คัดลอก `n` ไบต์จาก `src` ไป `dst` แล้ว**คืน `dst`** — **ไม่รองรับ overlap** (ใช้ `memmove` แทน) *(Copy `n` bytes `src`→`dst`; returns `dst`; overlap is undefined → use `memmove`)* |
| `ft_memmove` | คัดลอก `len` ไบต์แบบ**รองรับ overlap** (เลือกทิศทางตามตำแหน่ง src/dst) แล้ว**คืน `dst`** *(Overlap-safe copy; picks direction by src/dst; returns `dst`)* |
| `ft_memchr` | หา byte `c` ตัวแรกใน `n` ไบต์แรกของ `s` แล้ว**คืน pointer / NULL** — ไม่หยุดที่ `\0` *(Find first byte `c` in `n` bytes; returns pointer or NULL; does not stop at `\0`)* |
| `ft_memcmp` | เทียบ `n` ไบต์แรกของ `s1`/`s2` แบบ unsigned char แล้ว**คืนผลต่าง** (0 = เท่ากัน) *(Compare `n` bytes as unsigned char; returns difference)* |
| `ft_strlen` | นับความยาว string (ไม่รวม `\0`) แล้ว**คืน `size_t`** *(Length of string excluding `\0`; returns `size_t`)* |
| `ft_isalpha` | เช็คว่า `c` เป็นตัวอักษร A–Z / a–z **คืน 1 / 0** *(Is `c` alphabetic; returns 1 or 0)* |
| `ft_isdigit` | เช็คว่า `c` เป็นเลข 0–9 **คืน 1 / 0** *(Is `c` a digit; returns 1 or 0)* |
| `ft_isalnum` | เช็คว่า `c` เป็นตัวอักษรหรือเลข **คืน 1 / 0** *(Is `c` alphanumeric; returns 1 or 0)* |
| `ft_isascii` | เช็คว่า `c` อยู่ในช่วง ASCII 0–127 **คืน 1 / 0** *(Is `c` in ASCII range; returns 1 or 0)* |
| `ft_isprint` | เช็คว่า `c` เป็นอักขระพิมพ์ได้ (32–126) **คืน 1 / 0** *(Is `c` printable; returns 1 or 0)* |
| `ft_toupper` | แปลงตัวพิมพ์เล็กเป็นใหญ่ แล้ว**คืนตัวอักษร** — ถ้าไม่ใช่ a–z คืนค่าเดิม *(Lowercase → uppercase; returns the char, unchanged if not a–z)* |
| `ft_tolower` | แปลงตัวพิมพ์ใหญ่เป็นเล็ก แล้ว**คืนตัวอักษร** — ถ้าไม่ใช่ A–Z คืนค่าเดิม *(Uppercase → lowercase; returns the char, unchanged if not A–Z)* |
| `ft_strchr` | หา `c` ตัวแรกใน `s` แล้ว**คืน pointer / NULL** — ถ้า `c = '\0'` คืน pointer ที่ `\0` ท้าย *(Find first `c` in `s`; returns pointer or NULL; `c = '\0'` returns the terminating `\0`)* |
| `ft_strrchr` | หา `c` **ตัวสุดท้าย**ใน `s` แล้ว**คืน pointer / NULL** *(Find last `c` in `s`; returns pointer or NULL)* |
| `ft_strncmp` | เทียบ `s1`/`s2` อย่างมาก `n` ตัว แล้ว**คืนผลต่าง** (0 = เท่ากัน) *(Compare at most `n` chars; returns difference)* |
| `ft_strlcpy` | คัดลอก `src` ไป `dst` ภายใน `dstsize` (ปิด `\0` เสมอ) แล้ว**คืนความยาวของ `src`** — ไม่ใช่จำนวนที่คัดลอก; แม้ `dstsize = 0` ก็คืน `strlen(src)` *(Bounded, NUL-terminated copy; returns length of `src`, not bytes copied — even when `dstsize = 0`)* |
| `ft_strlcat` | ต่อ `src` ท้าย `dst` ภายใน `dstsize` แล้ว**คืนความยาวรวมที่ควรได้** — ถ้า `dstsize ≤ strlen(dst)` คืน `dstsize + strlen(src)` โดยไม่แตะ `dst` *(Append `src` to `dst`; returns total intended length; if `dstsize ≤ strlen(dst)` returns `dstsize + strlen(src)` untouched)* |
| `ft_strnstr` | หา `little` ใน `big` ภายใน `len` ตัวแรก แล้ว**คืน pointer / NULL** — `little` ว่าง คืน `big` *(Locate `little` within first `len` chars of `big`; returns pointer or NULL; empty `little` returns `big`)* |
| `ft_atoi` | แปลง string เป็น `int` (ข้าม whitespace + เครื่องหมายหนึ่งตัว) แล้ว**คืน int** — ใช้ `long` กัน overflow *(Convert string to `int`; skips whitespace + one sign; returns int)* |
| `ft_calloc` | จอง `count × size` ไบต์ + เติม 0 ทั้งหมด แล้ว**คืน pointer / NULL** — กัน overflow (`count > SIZE_MAX / size`) *(Allocate `count × size` zeroed bytes; returns pointer or NULL; guards overflow)* |
| `ft_strdup` | สำเนา string ไปยัง `malloc` ใหม่ แล้ว**คืน pointer / NULL** *(Duplicate string into fresh memory; returns pointer or NULL)* |

### Part 2 — Additional functions

| Function | Description |
|----------|-------------|
| `ft_substr` | สร้าง substring จาก `s` เริ่ม `start` ยาว `len` แล้ว**คืน string ใหม่ / NULL** — `start ≥ strlen(s)` คืน `""` ที่ malloc ใหม่ *(Create substring from `start` of length `len`; returns new string or NULL; `start ≥ strlen(s)` returns a fresh `""`)* |
| `ft_strjoin` | ต่อ `s1` + `s2` เป็น string ใหม่ แล้ว**คืน pointer / NULL** *(Concatenate `s1` and `s2` into a new string; returns pointer or NULL)* |
| `ft_strtrim` | ตัดอักขระที่อยู่ใน `set` ออกจากหัว-ท้ายของ `s1` แล้ว**คืน string ใหม่ / NULL** *(Trim chars in `set` from both ends of `s1`; returns new string or NULL)* |
| `ft_split` | แยก `s` ด้วยตัวคั่น `c` เป็น **array ของ string (`char **`)** ปิดท้ายด้วย NULL — malloc ล้มเหลวให้ free ทั้งหมด *(Split `s` by delimiter `c` into a NULL-terminated `char **`; frees all on malloc failure)* |
| `ft_itoa` | แปลง `int` เป็น string ที่ `malloc` ใหม่ แล้ว**คืน pointer / NULL** — รองรับ `INT_MIN` โดยใช้ `long` *(Convert `int` to a fresh string; returns pointer or NULL; INT_MIN-safe via `long`)* |
| `ft_strmapi` | ใช้ฟังก์ชัน `f(index, char)` กับทุกตัวอักษรของ `s` สร้าง string ใหม่ แล้ว**คืน pointer / NULL** *(Apply `f(index, char)` to each char, building a new string; returns pointer or NULL)* |
| `ft_striteri` | ใช้ฟังก์ชัน `f(index, &s[i])` กับทุกตัวอักษร **แก้ `s` ตรง ๆ (ไม่คืนค่า)** *(Apply `f(index, &s[i])` in place; no return)* |
| `ft_putchar_fd` | เขียนอักขระ `c` ลง file descriptor `fd` *(Write char `c` to `fd`)* |
| `ft_putstr_fd` | เขียน string `s` ลง `fd` *(Write string `s` to `fd`)* |
| `ft_putendl_fd` | เขียน `s` + ขึ้นบรรทัดใหม่ ลง `fd` *(Write `s` + newline to `fd`)* |
| `ft_putnbr_fd` | เขียนตัวเลข `n` ลง `fd` — รองรับ `INT_MIN` *(Write integer `n` to `fd`; INT_MIN-safe)* |

### Part 3 — Linked list

| Function | Description |
|----------|-------------|
| `ft_lstnew` | สร้าง node ใหม่ (เก็บ `content`, `next = NULL`) แล้ว**คืน node / NULL** *(Create new node with `content` and `next = NULL`; returns node or NULL)* |
| `ft_lstadd_front` | เพิ่ม node `new` ไว้หัว list (อัปเดต `*lst`) *(Add `new` at the front, updating `*lst`)* |
| `ft_lstsize` | นับจำนวน node แล้ว**คืน `unsigned int`** *(Count nodes; returns `unsigned int`)* |
| `ft_lstlast` | หา node สุดท้ายแล้ว**คืน pointer / NULL** (list ว่าง) *(Return last node or NULL if empty)* |
| `ft_lstadd_back` | เพิ่ม node `new` ท้าย list *(Add `new` at the back)* |
| `ft_lstdelone` | free 1 node โดยเรียก `del(content)` ก่อน — ไม่แตะ `next` *(Free one node, calling `del(content)` first; does not touch `next`)* |
| `ft_lstclear` | free ทั้ง list (เรียก `del` ทุก node) แล้วตั้ง `*lst = NULL` *(Free the whole list and set `*lst = NULL`)* |
| `ft_lstiter` | วนทุก node เรียก `f(content)` — ไม่สร้าง list ใหม่ *(Iterate calling `f(content)`; no new list)* |
| `ft_lstmap` | สร้าง list ใหม่โดยใช้ `f` กับ content ทุกโหนด แล้ว**คืน list ใหม่ / NULL** — malloc ล้มเหลวให้ free ทั้งหมด *(Map each node via `f` into a new list; returns new list or NULL; frees all on failure)* |

## Instructions

```sh
make        # สร้าง libft.a          (build libft.a)
make clean  # ลบ object files        (remove object files)
make fclean # ลบ object + libft.a    (remove objects and libft.a)
make re     # fclean + all           (rebuild from scratch)
```

## Resources

- Linux `man` pages — glibc / BSD documentation
- 42 project subject PDF (Libft v19.3)
- **AI usage:** AI assistants were used as learning support — explaining concepts, debugging, reviewing code, and generating test harnesses. All function implementations were written and verified by the student; no code was copied directly from any AI output.
  *(ใช้ AI เป็นตัวช่วยเรียน — อธิบายแนวคิด ดีบัก รีวิวโค้ด และสร้าง test harness; ตัว implementation ทุกฟังก์ชันเขียนและตรวจสอบโดยนักเรียนเอง ไม่ได้ก็อปโค้ดจาก AI ตรง ๆ)*
