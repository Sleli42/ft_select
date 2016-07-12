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

void		display_array(char **array) {
	int		ct = 0;

	while (array && array[ct])
		ft_putendl(array[ct++]);
}

void		display_list(t_clist *lst) {
	t_select	*tmp = lst->head;

	while (tmp)
	{
		ft_putendl(tmp->arg);
		tmp = tmp->next;
	}
}

int			define_maxlen_args(t_clist *lst)
{
	t_select	*tmp;
	int			len;

	tmp = lst->head;
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

void		add_spaces(int currlen, int maxlen)
{
	int		tmp;

	tmp = currlen;
	while (tmp++ <= maxlen)
		ft_putchar(' ');
}

void		display_arg(t_select *elem)
{
	if (elem->on_arg)
	{
		tputs_termcap("us");
	}
	else
		tputs_termcap("ue");
	if (elem->select_arg)
		tputs_termcap("mr");
	else
		tputs_termcap("me");
	ft_putstr(elem->arg);
}

void		horizontal_display(t_clist *lst, t_data *data)
{
	t_select	*tmp;
	int			ct;
	int			stop;

	tmp = lst->head;
	ct = 0;
	stop = 0;
	while (tmp)
	{
		if (stop >= data->max_elems_by_row)
		{
			stop = 0;
			ft_putchar('\n');
		}
		display_arg(tmp);
		// ft_putstr(tmp->arg);
		if (ct < (int)lst->lenght - 1)
			add_spaces((int)ft_strlen(tmp->arg), data->maxlen_arg + 2);
		ct += 1;
		stop += 1;
		tmp = tmp->next;
	}
	// ft_putchar('\n');
}

void		define_nb_lines_writed(t_clist *lst, t_data *data)
{
	t_select	*tmp;
	int			stop;
	int			line;

	tmp = lst->head;
	stop = 0;
	line = 0;
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
	data->nb_lines_writed = line + 1;
}

void		goto_first_line(t_data *data)
{
	int		ct;

	ct = 0;
	while (++ct < data->nb_lines_writed)
		tputs_termcap("up");
	ct = 0;
	while (++ct < data->max_cols)
		tputs_termcap("le");
}

void		refresh_screen(int nb_lines)
{
	int		ct;

	ct = 0;
	while (ct++ < nb_lines)
	{
		tputs_termcap("ce");
		tputs_termcap("cb");
		tputs_termcap("do");
	}
	while (--ct)
		tputs_termcap("up");
}

void		try_goto_next(t_clist *lst)
{
	t_select *tmp;

	tmp = lst->head;
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

void		select_loop(t_all *all)
{
	// display_list(all->select);
	// ft_putstr("\n\n");
	define_nb_args_by_row(all->select, all->data);
	define_nb_lines_writed(all->select, all->data);
	// printf("nbLinesWrited: %d\n", all->data->nb_lines_writed);
	// ft_putstr("\n\n");
	// printf("before display cursorRow: %d\n", all->data->curr_row);
	horizontal_display(all->select, all->data);
	get_cursor_row(all->data);
	// printf("currColumn: %d\n", all->data->curr_col);
	// exit(1);
	// printf("after display cursorRow: %d\n", all->data->curr_row);
	// printf("maxRows: %d\n", all->data->max_rows);
	// tputs_termcap("vi");
	goto_first_line(all->data);
	// tputs_termcap("sc");
	// ft_putchar('*');
	// refresh_screen(all->data->nb_lines_writed);
	all->select->head->select_arg = 1;
	// all->select->head->next->on_arg = 1;
	// all->select->head->select_arg = 1;
	// goto_first_line(all->data);
	// tputs_termcap("rc");
	// ft_putchar('*');
	// highlighted_first_choice()
	// tputs_termcap("vi");
	int		key = 0;
	while (1)
	{
		horizontal_display(all->select, all->data);
		if (!(key = read_keys()))
			return ;
		else if (key > 0)
		{
			goto_first_line(all->data);
		refresh_screen(all->data->nb_lines_writed);
			try_goto_next(all->select);
		}
	}
	// tputs_termcap("ve"); // cursor visible
}
