/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 17:26:20 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/10 17:26:20 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	min;
	size_t	i;
	char	*c;

	i = 0;
	slen = ft_strlen(s);
	if (start <= slen)
		min = slen - start;
	else
		min = 0;
	if (len < min)
		min = len;
	c = malloc(min + 1);
	if (!c)
		return (NULL);
	while (i < min && i <= len)
	{
		c[i] = s[start];
		i++;
		start++;
	}
	c[i] = '\0';
	return (c);
}
