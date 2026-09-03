/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:11:27 by awiriyok          #+#    #+#             */
/*   Updated: 2026/08/25 17:22:02 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char* ft_strchr(const char* s, int c)
{
    int i;
    i=0;
    while(s[i] != '\0')
    {
        if(s[i] == (char)c)
            return((char*)s+i);
        i++;
    }
    if(c == '\0')
        return ((char*)s+i); 
    return(NULL);
}
