/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 02:05:02 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/15 02:05:03 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		select_choice_extend(t_clist *lst, t_data *data, t_select **tmp)
{
	if ((*tmp) == lst->tail)
	{
		lst->head->on_arg = 1;
		(*tmp)->select_arg = ((*tmp)->select_arg) ? 0 : 1;
		data->curr_line = 1;
	}
	else
	{
		(*tmp)->select_arg = ((*tmp)->select_arg) ? 0 : 1;
		(*tmp)->next->on_arg = 1;
	}
}

void		select_choice(t_clist *lst, t_data *data)
{
	t_select	*tmp;

	tmp = lst->head;
	if (!tmp)
		return ;
	while (tmp)
	{
		if (tmp->on_arg)
		{
			tmp->on_arg = 0;
			if (data->curr_line < data->nb_lines_writed &&
				data->curr_line * data->max_elems_by_row == tmp->index)
				data->curr_line += 1;
			select_choice_extend(lst, data, &tmp);
			return ;
		}
		tmp = tmp->next;
	}
}

int			index_elem(t_clist *lst)
{
	t_select	*tmp;
	int			index;

	tmp = lst->head;
	index = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (tmp->on_arg)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (0);
}
