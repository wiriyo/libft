/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 20:07:26 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/08 20:07:26 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i;
    unsigned char *p;
    const unsigned char *r;

    i = 0;
    r = src;
    p = dst;
    while (i<n)
    {
        p[i] = r[i];
        i++;
    }
    return((void *)p);
}