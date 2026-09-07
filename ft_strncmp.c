/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 19:56:02 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/07 19:56:02 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    if (n == 0)
        return (0);
    while (i < n)
    {
        if(s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        if((s1[i] == '\0') && (s2[i] == '\0'))
            return (0);
        if(s1[i] == '\0')
            return (48-s2[i]);
        if(s2[i] == '\0')
            return (s1[i] - 48);
        i++;
    }
    return (0);
}

