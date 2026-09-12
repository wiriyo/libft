/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 17:40:59 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/12 18:18:16 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    size_t	i;
 
    i = 0;
    if (!s)
        return ; 
    while (s[i] != '\0')
    {
        f(i, &s[i]);
		i++;
    }
    return ;
}
