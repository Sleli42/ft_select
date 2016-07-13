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

int			check_if_str_already_exist(t_clist *ret, char *s2add)
{
	t_select	*tmp;
	int			ct;

	tmp = ret->head;
	ct = 0;
	if (tmp)
	{
		while (tmp)
		{
			if (!ft_strcmp(s2add, tmp->arg))
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

void		add_to_ret_list(t_clist *ret, char *s2add)
{
	if (!check_if_str_already_exist(ret, s2add))
		return ;
	clst_add_elem_back(ret, clst_create_elem(s2add));
}

void		select_choice(t_clist *lst, t_data *data, t_clist *ret)
{
	t_select	*tmp;

	tmp = lst->head;
	if (!tmp)
		return ;
	while (tmp)
	{
		if (tmp->on_arg)
		{
			add_to_ret_list(ret, tmp->arg);
			tmp->on_arg = 0;
			if (data->curr_line < data->nb_lines_writed &&
				data->curr_line * data->max_elems_by_row == tmp->index)
				data->curr_line += 1;
			if (tmp == lst->tail)
			{
				lst->head->on_arg = 1;
				tmp->select_arg = (tmp->select_arg) ? 0 : 1;
				data->curr_line = 1;
			}
			else
			{
				tmp->select_arg = (tmp->select_arg) ? 0 : 1;
				tmp->next->on_arg = 1;
			}
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
