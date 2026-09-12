/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awiriyok <awiriyok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 17:03:56 by awiriyok          #+#    #+#             */
/*   Updated: 2026/09/12 17:06:13 by awiriyok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"
#include <stdlib.h>

t_list *ft_lstnew(void *content){
    t_list *new_node = malloc(sizeof(t_list));
    if (new_node){
        return NULL;
    }
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}
