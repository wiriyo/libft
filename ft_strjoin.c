/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 19:57:06 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/10 19:57:06 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*x;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	x = malloc(s1len + s2len + 1);
	if (!x)
		return (NULL);
	s1len = ft_strlcpy(x, s1, s1len + 1);
	s2len = ft_strlcat(x, s2, (s1len + s2len + 1));
	return (x);
}
