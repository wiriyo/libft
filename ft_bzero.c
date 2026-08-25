/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 15:52:14 by awiriyok          #+#    #+#             */
/*   Updated: 2026/08/25 16:14:54 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero(void *s,size_t n)
{
    unsigned char *ptr;
    size_t i;

    
    ptr = (unsigned char *)s;
    i = 0;
    while(i < n)
    {
            ptr[i] = 0;
            i++;
    }
}