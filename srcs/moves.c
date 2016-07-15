/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 22:34:19 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/12 22:34:20 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			len_array(char **array)
{
	int		ret;
	char	**tmp;

	ret = 0;
	tmp = array;
	while (tmp && tmp[ret])
		ret++;
	return (ret);
}

void		try_down_moves(t_clist *lst, t_data *data)
{
	t_select	*tmp;
	int			ct;

	tmp = lst->head;
	ct = 0;
	if (data->curr_line < data->nb_lines_writed
		&& index_elem(lst) + data->max_elems_by_row < (int)lst->lenght)
		data->curr_line += 1;
	else
		return (tputs_termcap("bl"));
	while (tmp)
	{
		if (tmp->on_arg)
		{
			tmp->on_arg = 0;
			while (ct++ < data->max_elems_by_row)
				tmp = tmp->next;
			tmp->on_arg = 1;
			return ;
		}
		tmp = tmp->next;
	}
}

void		try_up_moves(t_clist *lst, t_data *data)
{
	t_select	*tmp;
	int			ct;

	tmp = lst->tail;
	ct = 0;
	if (data->curr_line > 1)
		data->curr_line -= 1;
	else
	{
		tputs_termcap("bl");
		return ;
	}
	while (tmp)
	{
		if (tmp->on_arg)
		{
			tmp->on_arg = 0;
			while (ct++ < data->max_elems_by_row)
				tmp = tmp->prev;
			tmp->on_arg = 1;
			return ;
		}
		tmp = tmp->prev;
	}
}

void		try_horizontal_moves(t_clist *lst, t_data *data, int key)
{
	t_select	*tmp;

	tmp = lst->head;
	while (tmp)
	{
		if (tmp->on_arg)
		{
			tmp->on_arg = 0;
			if (key == K_LEFT && tmp != lst->head)
				left_key(&tmp, data);
			else if (key == K_LEFT && tmp == lst->head)
				goto_last_elem(lst, data);
			if (key == K_RIGHT && tmp != lst->tail)
				right_key(&tmp, data);
			else if (key == K_RIGHT && tmp == lst->tail)
				goto_first_elem(lst, data);
			return ;
		}
		tmp = tmp->next;
	}
}
