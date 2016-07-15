/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 02:37:48 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/15 02:37:56 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		create_ret_list(t_all *all)
{
	t_select	*tmp;

	tmp = all->select->head;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->select_arg)
				clst_add_elem_back(all->ret_list, clst_create_elem(tmp->arg));
			tmp = tmp->next;
		}
	}
}

int			define_maxlen_args(t_clist *lst)
{
	t_select	*tmp;
	int			len;

	tmp = lst->head;
	if (!tmp)
		return (0);
	len = (int)ft_strlen(tmp->arg);
	while (tmp && tmp->next)
	{
		if (len < (int)ft_strlen(tmp->next->arg))
			len = (int)ft_strlen(tmp->next->arg);
		tmp = tmp->next;
	}
	return (len);
}

int			nb_spaces_2_add(int currlen, int maxlen)
{
	int		to_add;

	to_add = 2;
	to_add += maxlen - currlen;
	return (to_add);
}

void		define_nb_args_by_row(t_clist *lst, t_data *data)
{
	int			stop;
	int			ct;
	t_select	*tmp;

	stop = 0;
	ct = 0;
	tmp = lst->head;
	if (!tmp)
		return ;
	data->maxlen_arg = define_maxlen_args(lst);
	while (tmp)
	{
		if (stop >= data->max_cols)
		{
			data->max_elems_by_row = (ct - 1);
			break ;
		}
		stop += (int)ft_strlen(tmp->arg);
		stop += nb_spaces_2_add((int)ft_strlen(tmp->arg), data->maxlen_arg);
		tmp = tmp->next;
		ct += 1;
	}
	if (!data->max_elems_by_row)
		data->max_elems_by_row = (int)lst->lenght;
}

void		define_nb_lines_writed(t_clist *lst, t_data *data)
{
	t_select	*tmp;
	int			stop;
	int			line;

	tmp = lst->head;
	stop = 0;
	line = 1;
	if (!tmp)
		return ;
	while (tmp)
	{
		if (stop == data->max_elems_by_row)
		{
			line += 1;
			stop = 0;
		}
		stop += 1;
		tmp = tmp->next;
	}
	data->nb_lines_writed = line;
}
