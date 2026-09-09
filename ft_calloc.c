/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 12:18:16 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/09 12:18:16 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void *ft_calloc(size_t count, size_t size)
{
    unsigned char *p;
    size_t x;

    x = count * size;
    p = malloc(x);
    if (p == NULL)
        return (NULL);
    ft_bzero(p, x);
    return (p);
}