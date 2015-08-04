/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 03:15:08 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/04 18:41:20 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_all	*init_all(int ac, char **av)
{
	t_all	*all;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
		return (NULL);
	init_termios(all->term);
	all->lst = create_circular_list(ac, av);
	all->maxlen = define_maxlen(all->lst);
	all->tty = init_tty();
	init_windows_size(all);
	return (all);
}

void	init_windows_size(t_all *all)
{
	if (ioctl(all->tty, TIOCGWINSZ, &all->ws) == -1)
		term_error("ioctl");
}

int		init_tty(void)
{
	int		tty;

	if ((tty = ttyslot()) == -1)
		return (-1);
	if (isatty(tty) == 0)
		return (NOTATTY);
	return (tty);
}

void	init_termios(t_termios term)
{
	char	*term_name;

	if ((term_name = getenv("TERM")) == NULL)
		term_error("getenv");
	if (tgetent(NULL, term_name) == -1)
		term_error("tgetent");
	if (tcgetattr(0, &term) == -1)
		term_error("tcgetattr[init]");
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 0;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		term_error("tcsetattr[init]");
}
