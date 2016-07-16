/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 23:45:45 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/11 23:46:00 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		init_loop(t_all *all)
{
	tputs_termcap("cl");
	define_nb_args_by_row(all->select, all->data);
	define_nb_lines_writed(all->select, all->data);
	if (all->data->nb_lines_writed > all->data->max_rows)
	{
		ft_putendl("screen too small: too many elems 2 display");
		exit(1);
	}
	horizontal_display(all->select, all->data);
	get_cursor_row(all->data);
	goto_first_line(all->data);
	all->select->head->on_arg = 1;
	tputs_termcap("vi");
}

void		reset_loop(t_all *all)
{
	tputs_termcap("ue");
	tputs_termcap("me");
	goto_first_line(all->data);
	refresh_screen(all->data->nb_lines_writed);
	create_ret_list(all);
	display_lst(all->ret_list);
	free_all(all);
}

void		init_windows_size(t_data *data)
{
	if (ioctl(init_tty(), TIOCGWINSZ, &data->ws) == -1)
		term_error("ioctl");
	data->max_rows = tgetnum("li");
	data->max_cols = tgetnum("co");
}

int			init_tty(void)
{
	int		tty;

	if ((tty = ttyslot()) == -1)
		return (-1);
	if (isatty(tty) == 0)
		return (NOTATTY);
	return (tty);
}

t_all		*init_all(char **env)
{
	t_all		*all;

	all = NULL;
	if (!(all = (t_all *)malloc(sizeof(t_all))))
		error("MALLOC");
	all->env = env;
	all->dupenv = ft_dupenv(env);
	all->data = NULL;
	if (!(all->data = (t_data *)malloc(sizeof(t_data))))
		error("MALLOC");
	all->data->max_rows = 0;
	all->data->curr_line = 1;
	init_term(all, all->dupenv);
	init_windows_size(all->data);
	all->select = create_clst();
	all->ret_list = create_clst();
	all->key_arrow = 0;
	return (all);
}
