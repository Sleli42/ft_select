/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 02:08:46 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/15 02:08:47 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		left_key(t_select **tmp, t_data *data)
{
	(*tmp) = (*tmp)->prev;
	if (data->curr_line > 1 &&
		(data->curr_line - 1) * data->max_elems_by_row == (*tmp)->index)
		data->curr_line -= 1;
	(*tmp)->on_arg = 1;
}

void		right_key(t_select **tmp, t_data *data)
{
	if (data->curr_line < data->nb_lines_writed &&
		(data->curr_line * data->max_elems_by_row) == ((*tmp)->index + 1))
		data->curr_line += 1;
	(*tmp) = (*tmp)->next;
	(*tmp)->on_arg = 1;
}

void		goto_first_elem(t_clist *lst, t_data *data)
{
	lst->head->on_arg = 1;
	data->curr_line = 1;
}

void		goto_last_elem(t_clist *lst, t_data *data)
{
	lst->tail->on_arg = 1;
	data->curr_line = data->nb_lines_writed;
}
