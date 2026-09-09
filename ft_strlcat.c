/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:57:22 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/09 13:57:22 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t i;
    size_t len;
    size_t lend;

    len = ft_strlen(src);
    lend = ft_strlen(dst);
    i = 0;
    if (lend >= dstsize)
        return (dstsize+len);
    while (i < dstsize - lend - 1 && src[i] != '\0')
    {
        dst[lend + i] = src[i];
        i++;
    }
    dst[lend + i] = '\0';
    return (lend + len);
}