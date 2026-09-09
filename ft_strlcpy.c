/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 13:19:35 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/09 13:19:35 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;
    size_t len;

    i = 0;
    len = ft_strlen(src);
    if (dstsize == 0)
        return (len);
    while (i < dstsize - 1)
    {
        if (src[i] == '\0')
        {
            dst[i] = '\0';
            return (i);
        }
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (len);
}