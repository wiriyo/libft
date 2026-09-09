/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:21:49 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/09 11:21:49 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;
    const unsigned char *p;
    const unsigned char *q;

    i = 0;
    p = s1;
    q = s2;

    while (i < n)
    {
        if (p[i] != q[i])
            return (p[i] - q[i]);
        i++;
    }
    return (0);
}