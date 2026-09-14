*This project has been created as part of the 42 curriculum by `awiriyok`.*

# libft

Libft is the first project of the 42 cursus: a personal implementation of a subset of the C standard library, plus additional utility functions and linked-list manipulation functions, meant to be reused throughout the curriculum.

## Contents

- **Part 1 — Libc functions:** `memset`, `bzero`, `memcpy`, `memmove`, `memchr`, `memcmp`, `calloc`, `strlen`, `strlcpy`, `strlcat`, `strchr`, `strrchr`, `strnstr`, `strncmp`, `strdup`, `atoi`, `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `toupper`, `tolower`
- **Part 2 — Additional functions:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- **Part 3 — Linked list:** `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Build

```
make        # builds libft.a
make clean  # removes object files
make fclean # removes object files and libft.a
make re     # fclean + all
```

## Resources

- Linux `man` pages (glibc / BSD documentation)
- The 42 project subject PDF (Libft v19.3)
- AI assistants were used as learning support for explaining concepts, debugging, and reviewing code. All functions were implemented and verified by the student; no code was copied directly from any AI output.
