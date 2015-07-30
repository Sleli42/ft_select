/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 03:52:24 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/30 20:22:57 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		move_cursor_up(t_circular **lst)
{
	t_circular	*tmp;

	tmp = (*lst)->next;
	while (tmp)
	{
		if (tmp->onArg == 1)
		{
			tmp->onArg = 0;
			if (tmp->prev->arg == NULL)
				tmp->prev->prev->onArg = 1;
			else
				tmp->prev->onArg = 1;
			return (1);

		}
		tmp = tmp->next;
	}
	return (0);
}

int		move_cursor_down(t_circular **lst)
{
	t_circular	*tmp;

	tmp = (*lst)->next;
	while (tmp)
	{
		if (tmp->onArg == 1)
		{
			tmp->onArg = 0;
			if (tmp->next->arg == NULL)
				tmp->next->next->onArg = 1;
			else
				tmp->next->onArg = 1;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		select_cursor(t_circular **lst)
{
	t_circular	*tmp;

	tmp = (*lst)->next;
	while (tmp)
	{
		if (tmp->onArg == 1 && tmp->select == 0)
		{
			tmp->onArg = 0;
			tmp->select = 1;
			tmp->next->onArg = 1;
			return (1);
		}
		if (tmp->onArg == 1 && tmp->select == 1)
		{
			tmp->onArg = 0;
			tmp->select = 0;
			tmp->next->onArg = 1;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
