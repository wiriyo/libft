/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 20:21:19 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/12 20:21:19 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t	i;
	size_t	len;
	char	*c;

	i = 0;
	while(!s)
		return (NULL);
	len = ft_strlen(s);
	c = malloc(len + 1);
	while(!c)
		return (NULL);
	while (i < len)
	{
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
