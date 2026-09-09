/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 16:26:17 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/09 16:26:17 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;
    size_t llen;


    j = 0;
    i = 0;
    llen = ft_strlen(little);
    if (llen == 0)
        return((char *)big);
    while (i < len && big[i] != '\0')
    {
        while (big[i+j] == little[j] && (i+j) < len )
        {
            j++;
            if (little[j+1] == '\0')
                return ((char *)big + i );
        }
        i++;
        j = 0;
    }
    return(NULL);
}
