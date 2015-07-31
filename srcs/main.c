/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 00:59:50 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/31 21:14:51 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	loop(t_all *all)
{
	int			ret;

	tputs_termcap("cl");
	tputs_termcap("vi");
	tputs_termcap("ho");
	display_list(all->lst);
	while (1091111096051)
	{
		f_cpy(all);
		ret = key_hook(all->lst);
		if (ret == 1)
		{
			tputs_termcap("cl");
			display_list(all->lst);
		}
		else if (ret == -1 || c_list_size(all->lst) == 0)
			return ;
	}
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
		term_error("tcgetattr[reset]");
	if (tcsetattr(0, 0, &default_term) == -1)
		term_error("tcsetattr[reset]");
}
