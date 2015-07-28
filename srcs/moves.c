/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 03:52:24 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/28 20:17:48 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_cursor_up(t_circular **lst)
{
	t_circular	*tmp;

	tmp = *lst;
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

void	move_cursor_down(t_circular **lst)
{
	t_circular	*tmp;

	tmp = *lst;
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

void	select_cursor(t_circular **lst)
{
	t_circular	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->onArg == 1 && tmp->select == 0)
		{
			tmp->onArg = 0;
			tmp->select = 1;
			tmp->next->onArg = 1;
			return ;
		}
		if (tmp->onArg == 1 && tmp->select == 1)
		{
			tmp->onArg = 0;
			tmp->select = 0;
			tmp->next->onArg = 1;
			return ;
		}
		tmp = tmp->next;
	}
}
