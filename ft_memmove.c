/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 20:49:29 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/08 20:49:29 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t n)
{
    size_t i;
    unsigned char *p;
    const unsigned char *r;

    
    p = dst;
    r = src;
    if (p > r)
    {   
        i = n;
        while (i > 0)
        {
         i--;
         p[i] = r[i];
        }   
    }
    if (p < r)
    {
        i = 0;
        while (i < n)
        {
            p[i] = r[i];
            i++;
        }
    }
    return ((void *)p);
}
