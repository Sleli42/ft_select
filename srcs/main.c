/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 23:36:25 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/11 23:36:26 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int ac, char **av, char **env)
{
	t_all	*all;
	int		ct;

	all = init_all(env);
	ct = 0;
	if (ac > 1)
	{
		while (++ct < ac)
			clst_add_elem_back(all->select, clst_create_elem(av[ct]));
		select_loop(all);
	}
	else
		ft_putendl("Need more args !");
	reset_term();
	return (0);
}