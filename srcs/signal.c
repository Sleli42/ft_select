/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 22:28:50 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/30 22:14:09 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct termios  *g_dat;

void	term_clear(void)
{
	tputs_termcap("cl");
	tputs_termcap("te");
	tputs_termcap("ve");
	// tputs_termcap("me");
	// tputs_termcap("cl");
}

void	ft_func(int sig)
{
	if (sig == SIGTSTP)
	{
		char	cp[2];

		ft_putendl("stopping... \n");
		term_clear();
		signal(SIGTSTP, SIG_DFL);
   		ioctl(0, TIOCSTI, cp);
	}
	if (sig == SIGCONT)
	{
		signal(SIGTSTP, ft_func);
	}
	if (sig == SIGINT)
	{
		printf("ctrl-c\n");
		exit(1);
	}
}

void	ft_catch_sig(void)
{
	int sig;

	sig = 1;
	while (sig <= 31)
	{
		signal(sig++, ft_func);
	}
}
