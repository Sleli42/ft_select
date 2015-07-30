/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 00:59:50 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/30 22:13:54 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		key_hook(t_circular *lst)
{
	char	buff[3] = {0};

	read(0, buff, 3);
	if (K_UP)
		return (move_cursor_up(&lst));
	if (K_DOWN)
		return (move_cursor_down(&lst));
	if (K_SPACE)
		return (select_cursor(&lst));
	if (K_BACKSPACE || K_DELETE)
		return (delete_elem(&lst));
	if ((buff[0] == 4 && !buff[1] && !buff[2]) || K_ECHAP)
		return (-1);
	return (0);
}

void	loop(t_all *all)
{
	int			ret;

	tputs_termcap("cl");
	tputs_termcap("vi");
	tputs_termcap("ho");
	display_list(all->lst);
	while (1091111096051)
	{
		global_cpy(all->lst);
		ret = key_hook(all->lst);
		if (ret == 1)
		{
			tputs_termcap("cl");
			display_list(all->lst);
		}
		else if (ret == -1 || list_size(all->lst) == 0)
			return ;
	}
}

t_circular	*global_cpy(t_circular *list)
{
	static t_circular *cpy;

	if (list)
		cpy = list;
	return (cpy);
}

int		main(int ac, char **av)
{
	t_all	*all;

	all = NULL;
	if (ac > 1)
	{
		ft_catch_sig();
		all = init_all(ac, av);
		loop(all);
		if (all->lst)
			del_circular_list(&all->lst);
		reset_term(all->default_term);
	}
	return (0);
}

void	reset_term(t_termios default_term)
{
	tputs_termcap("ve");
	if (tcgetattr(0, &default_term) == -1)
		termError("tcgetattr[reset]");
	if (tcsetattr(0, 0, &default_term) == -1)
		termError("tcsetattr[reset]");
}
