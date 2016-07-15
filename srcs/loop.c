/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 00:24:40 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/12 00:24:41 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		select_loop(t_all *all)
{
	int		key;

	key = 0;
	if (!all)
		all = init_all(all->dupenv);
	init_loop(all);
	while (1)
	{
		all = f_cpy(all);
		if (!all->select->lenght)
			break ;
		horizontal_display(all->select, all->data);
		if (!(key = read_keys(all)))
			break ;
		else if (key > 0)
		{
			goto_first_line(all->data);
			refresh_screen(all->data->nb_lines_writed);
			parse_keys(all, all->key_arrow);
		}
	}
	reset_loop(all);
}
