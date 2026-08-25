/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 11:45:50 by awiriyok          #+#    #+#             */
/*   Updated: 2026/08/25 12:51:32 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void ft_putnbr(int n)
{
    long nb;
    nb = n;
    if(nb<0)
    {
        ft_putchar('-');
        nb = nb*-1;
    }
    if(nb>9)
        ft_putnbr(nb/10);
    ft_putchar(nb%10 + '0');
    
}