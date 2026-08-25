/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:37:51 by awiriyok          #+#    #+#             */
/*   Updated: 2026/08/25 16:45:15 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
    unsigned char *ptr;
    size_t i;

    ptr = (unsigned char *)b;
    i = 0;
    while(i < len)
    {
        ptr[i] = c;
        i++;
    }
    return(ptr);
}