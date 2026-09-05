/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 22:29:13 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/05 22:29:13 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    size_t i;
    
    i = ft_strlen(s);
    while (i > 0)
    {
        if (s[i] == (char)c)
            return ((char *)s + i);
        i--;
    }
    if (s[i] == (char)c)
        return ((char *)s);
    return (NULL);
}