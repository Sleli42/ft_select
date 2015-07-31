/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 22:28:50 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/31 21:14:00 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	c_list_del_one(t_circular *elem)
{
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
	ft_strdel(&elem->arg);
	free(elem);
}

static void	resize_win(void)
{
	tputs_termcap("cl");
	init_windows_size(f_cpy(NULL));
	if (f_cpy(NULL)->ws.ws_row <= c_list_size(f_cpy(NULL)->lst)
		|| f_cpy(NULL)->ws.ws_col < f_cpy(NULL)->maxlen)
		ft_putstr("Screen too small\n");
	else
		display_list(f_cpy(NULL)->lst);
}

void	ft_func(int sig)
{
	if (sig == SIGTSTP)
	{
		char	cp[2] = {f_cpy(NULL)->term.c_cc[VSUSP], 0};

		reset_term(f_cpy(NULL)->term);
		signal(SIGTSTP, SIG_DFL);
   		ioctl(0, TIOCSTI, cp);
	}
	if (sig == SIGCONT)
	{
		init_termios(f_cpy(NULL)->default_term);
		loop(f_cpy(NULL));
		signal(SIGTSTP, ft_func);
	}
	if (sig == SIGWINCH)
	{
		resize_win();
		signal(SIGWINCH, ft_func);
	}
	if (sig == SIGINT)
		exit(1);
}

void	ft_catch_sig(void)
{
	int sig;

	sig = 1;
	while (sig <= 31)
		signal(sig++, ft_func);
}
