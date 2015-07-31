/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_list_del_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 20:55:02 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/31 21:11:58 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	c_list_del_one(t_circular *elem, void *content)
{
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
	ft_strdel(&elem->content);
	free(elem);
}
