/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 03:52:24 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/28 04:18:58 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_cursor_updown(char *key, t_circular **lst)
{
	t_circular	*tmp;

	tmp = *lst;
	if (ft_strcmp(key, "K_UP"))
	{
		while (tmp)
		{
			if (tmp->onArg == 1)
			{
				tmp->onArg = 0;
				tmp->next->onArg = 1;
				return ;
			}
			tmp = tmp->next;
		}
	}
	if (ft_strcmp(key, "K_DOWN"))
	{
		while (tmp)
		{
			if (tmp->onArg == 1)
			{
				tmp->onArg = 0;
				tmp->prev->onArg = 1;
				return ;
			}
			tmp = tmp->next;
		}
	}
}
