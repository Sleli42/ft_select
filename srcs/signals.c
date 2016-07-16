/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 04:45:19 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/16 04:45:21 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			sig_cont(int sig)
{
	t_all	*all;

	all = NULL;
	if ((all = f_cpy(NULL)) == NULL)
		return (ft_putendl("no signal"));
	if (sig == SIGCONT)
	{
		init_term(all, all->dupenv);
		init_windows_size(all->data);
		define_nb_args_by_row(all->select, all->data);
		define_nb_lines_writed(all->select, all->data);
		tputs_termcap("vi");
		if (all->data->maxlen_arg > all->data->max_cols)
			return (ft_putstr("Too small screen\n"));
		horizontal_display(all->select, all->data);
	}
}

void			sig_winch(int sig)
{
	t_all	*all;

	all = NULL;
	if ((all = f_cpy(NULL)) == NULL)
		return (ft_putendl("no signal"));
	if (sig == SIGWINCH)
	{
		reset_term(all);
		init_term(all, all->dupenv);
		init_windows_size(all->data);
		define_nb_args_by_row(all->select, all->data);
		define_nb_lines_writed(all->select, all->data);
		tputs_termcap("cl");
		if (all->data->maxlen_arg > all->data->max_cols)
			return (ft_putstr("Too small screen\n"));
		horizontal_display(all->select, all->data);
	}
}

void			sig_tstp(int sig)
{
	t_all	*all;
	char	cp[2];

	all = NULL;
	if ((all = f_cpy(NULL)) == NULL)
		return (ft_putendl("no signal"));
	if (sig == SIGTSTP)
	{
		cp[0] = all->term.c_cc[VSUSP];
		cp[1] = 0;
		all->term.c_lflag |= (ICANON | ECHO);
		signal(SIGTSTP, SIG_DFL);
		tcsetattr(0, 0, &(all->term));
		tputs_termcap("ve");
		ioctl(0, TIOCSTI, cp);
	}
}

void			sig_int(int sig)
{
	t_all	*all;

	all = NULL;
	if ((all = f_cpy(NULL)) == NULL)
		return (ft_putendl("no signal"));
	if (sig == SIGINT)
	{
		tputs_termcap("ve");
		reset_term(all);
		free_all(all);
		ft_putchar('\n');
		exit(1);
	}
}
