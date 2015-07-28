/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 00:59:50 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/28 20:24:52 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		key_hook(t_circular *lst)
{
	char	buff[3] = {0};

	read(0, buff, 3);
	if (K_UP)
	{
		move_cursor_up(&lst);
		return (1);
	}
	if (K_DOWN)
	{
		move_cursor_down(&lst);
		return (1);
	}
	if (K_SPACE)
	{
		select_cursor(&lst);
		return (1);
	}
	if (!buff)
		return (-1);
	return (0);
}

void	loop(t_all *all)
{
	tputs_termcap("cl");
	tputs_termcap("vi");
	tputs_termcap("ho");
	display_list(&all->lst);
	while (1091111096051)
	{
		if (key_hook(all->lst) == 1)
		{
			tputs_termcap("cl");
			display_list(&all->lst);
		}
	}
}

int		main(int ac, char **av)
{
	t_all	*all;

	all = NULL;
	if (ac > 1)
	{
		all = init_all(ac, av);
		loop(all);
	//	del_circular_list(all->lst);
	}
	reset_term(all->default_term);
	return (0);
}

void	reset_term(t_termios *default_term)
{
	if (tcgetattr(0, default_term) == -1)
   		return ;
	default_term->c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, default_term) == -1)
   		return ;
}
