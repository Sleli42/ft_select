/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 03:15:08 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/18 00:35:38 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_all	*init_all(int ac, char **av)
{
	t_all	*all;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
		return (NULL);
	init_termios(all->default_term, "DEFAULT");
	init_termios(all->term, "NORMAL");
	if (all->term)
		all->lst = create_circular_list(ac, av);
	return (all);
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


void	init_termios(struct termios *term, char *s)
{
	char	*term_name;

	if (!(term = (struct termios *)malloc(sizeof(struct termios))))
		return ;
	if ((term_name = getenv("TERM")) == NULL)
		termError("getenv");
	if (tgetent(NULL, term_name) == -1)
		termError("tgetent");
	if (tcgetattr(0, term) == -1)
		termError("tcgetattr");
	if (ft_strcmp(s, "DEFAULT") != 0)
	{
		term->c_lflag &= ~(ICANON); // canonique mode
		term->c_lflag &= ~(ECHO); // plus d'entree standard
		term->c_cc[VMIN] = 0;
		term->c_cc[VTIME] = 0; // refresh
		if (tcsetattr(0, TCSADRAIN, term) == -1)
			termError("tcsetattr");
	}
}
