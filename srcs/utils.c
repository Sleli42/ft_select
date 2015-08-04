/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 20:52:33 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/04 18:59:37 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_all	*f_cpy(t_all *list)
{
	static t_all *cpy;

	if (list)
		cpy = list;
	return (cpy);
}

size_t	define_maxlen(t_circular *lst)
{
	t_circular	*tmp;
	size_t		max;

	tmp = lst;
	max = tmp->lenArg;
	while (tmp->next)
	{
		if (max < (size_t)tmp->next->lenArg)
			max = tmp->next->lenArg;
		tmp = tmp->next;
		if (tmp == lst)
			break ;
	}
	return (max);
}

int		delete_elem(t_circular **lst)
{
	t_circular	*temp;

	temp = (*lst)->next;
	if (temp->next == *lst)
	{
		c_list_del_one(temp);
		return (1);
	}
	while (temp)
	{
		if (temp->onArg == 1)
		{
			c_list_del_one(temp);
			if (temp->next->arg != NULL)
				temp->next->onArg = 1;
			else
				temp->next->next->onArg = 1;
			return (1);
		}
		temp = temp->next;
		if (temp == *lst)
			break ;
	}
	return (-1);
}

int		key_hook(t_circular *lst)
{
	char	buff[3] = {0};

	read(0, buff, 3);
	if (K_UP)
		return (move_cursor_up(&lst));
	if (K_DOWN)
		return (move_cursor_down(&lst));
	if (K_SPACE)
		return (select_cursor(&lst));
	if (K_BACKSPACE || K_DELETE)
		return (delete_elem(&lst));
	if (K_ENTER)
		return (display_choices(&lst));
	if ((buff[0] == 4 && !buff[1] && !buff[2]) || K_ECHAP)
		return (-1);
	return (0);
}
