/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:04:08 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/09 16:56:27 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

# include <stddef.h>

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
size_t ft_strlen(const char *s);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
void ft_putchar(char c);
void ft_putstr(char *s);
void ft_putendl(char *s);
void ft_putnbr(int n);
void ft_bzero(void *s, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_memmove(void *dst, const void *src, size_t n);
void *ft_memcpy(void *dst, const void *src, size_t n);
void *ft_memset(void *b,int c, size_t len);
void *ft_memchr(const void *s, int c, size_t n);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char* s, int c);
char *ft_strdup(const char *s1);
char *ft_strnstr(const char *big, const char *little, size_t len);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void *ft_calloc(size_t count, size_t size);
int ft_toupper(int c);
int ft_tolower(int c);

#endif