/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 22:28:50 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/31 00:59:44 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
