/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 03:15:08 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/15 05:46:20 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_all	*init_all(void)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	init_termios(all);
}

int		init_tty(void)
{
	int		tty;

	if ((tty = ttyslot()) == -1)
	{
		printf("no term found\n");
		return (-1);
	}
	if (!isatty(tty))
	{
		printf("fd not open\n");
		return (NOTATTY);
	}
	return (tty);
}


void	init_termios(t_all *all)
{
	char	*term_name;

	if ((term_name = getenv("TERM")) == NULL)
		return ;
	if (tgetent(NULL, &term_name) == -1)
		return ;
	all->default_term =
}
