/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 00:59:50 by lubaujar          #+#    #+#             */
/*   Updated: 2015/07/24 00:12:33 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


int		main(int ac, char **av)
{
	t_all	*all;

	all = NULL;
	if (ac > 1)
	{
		all = init_all(ac, av);
		// display_screen(all);
		print_list(all->lst, ac);
	//	del_circular_list(all->lst);
	}
	return (0);
}

void	print_list(t_circular *lst)
{
	t_circular *tmp;

	tmp = lst;
	if (tmp)
	{
		while (tmp)
		{
			printf("%s\n", tmp->arg);
			tmp = tmp->next;
		}
	}
}
