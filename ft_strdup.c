/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:49:04 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/09 11:49:04 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strdup(const char *s1)
{
    size_t i;
    size_t len;
    char *p;

    len = ft_strlen(s1);
    p = malloc(len+1);
    i = 0;
    if (p == NULL)
        return (NULL);
    while (i <= len)
    {
        p[i] = s1[i];
        i++;
    }
    return (p);
}
