/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 09:59:40 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/12 17:21:17 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t	count(long n)
{
    size_t  i;
    
    i = 1;
    if (n < 0)
        n = n * (-1);
    while (n > 9)
    {
        n = n / 10;
    	i++;
    }
    return(i);
}

char *ft_itoa(int n)
{
    size_t  i;
    size_t  j;
    char    *c;
    long    l;

    l = n;
    i = count(l);
    c = malloc(i + (n < 0) + 1);
    if (!c)
        return (NULL);
    if (n < 0)
        l = l * (-1);
    j = i + (n < 0);
        c[j] = '\0';
    while (i > 0)
    {
        i--;
        j--;
        c[j] = l % 10 + '0';
        l = l / 10;
    }
    if (n < 0)
        c[0] = '-';
    return (c);
}
