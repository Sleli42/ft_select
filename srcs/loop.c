/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 00:24:40 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/12 00:24:41 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
	// printf("maxlenArg: %d\n", data->maxlen_arg);
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
		// printf("stop: %d && maxColumns: %d\n", stop, data->max_cols);
	}
	if (!data->max_elems_by_row)
		data->max_elems_by_row = (int)lst->lenght;
	// printf("maxElemsByRows: %d\n", data->max_elems_by_row);
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

void		try_goto_next(t_clist *lst)
{
	t_select *tmp;

	tmp = lst->head;
	if (!tmp)
		return ;
	while (tmp)
	{
		if (tmp->select_arg && tmp->next)
		{
			tmp->select_arg = 0;
			tmp->next->select_arg = 1;
			break ;
		}
		tmp = tmp->next;
	}
}

void		display_array(char **array) {
	int		ct = 0;

	while (array && array[ct]) {
		ft_putendl(array[ct]);
		ct++;
	}
}

void		display_lst(t_clist *lst)
{
	t_select	*tmp;

	tmp = lst->head;
	if (!tmp)
		return ;
	while (tmp)
	{
		ft_putendl(tmp->arg);
		// printf("index: %d\n", tmp->index);
		tmp = tmp->next;
	}
}

void		select_loop(t_all *all)
{
	define_nb_args_by_row(all->select, all->data);
	define_nb_lines_writed(all->select, all->data);
	horizontal_display(all->select, all->data);
	get_cursor_row(all->data);
	goto_first_line(all->data);
	all->select->head->on_arg = 1;
	tputs_termcap("vi");
	int		key = 0;
	while (1)
	{
		if (!all->select->lenght)
			break ;
		horizontal_display(all->select, all->data);
		if (!(key = read_keys(all)))
			break ;
		else if (key > 0)
		{
			goto_first_line(all->data);
			refresh_screen(all->data->nb_lines_writed);
			parse_keys(all, all->key_arrow);
		}
	}
	tputs_termcap("ue");
	tputs_termcap("me");
	goto_first_line(all->data);
	refresh_screen(all->data->nb_lines_writed);
	display_lst(all->ret_list);
	del_clist(&all->select);
	del_clist(&all->ret_list);
}
