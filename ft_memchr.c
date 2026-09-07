/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:29:28 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/07 21:29:28 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    const unsigned char *p;
    

    i = 0;
    p = s;
    while (i < n)
    {
        if (p[i] == (unsigned char)c)
            return ((void *)(p+i));
        i++;
    }
    return (NULL);
}