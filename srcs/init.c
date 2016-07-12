/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 23:45:45 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/11 23:46:00 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		init_windows_size(t_data *data)
{
	if (ioctl(init_tty(), TIOCGWINSZ, &data->ws) == -1)
		term_error("ioctl");
	data->max_rows = tgetnum("li");
	data->max_cols = tgetnum("co");
}

int			init_tty(void)
{
	int		tty;

	if ((tty = ttyslot()) == -1)
		return (-1);
	if (isatty(tty) == 0)
		return (NOTATTY);
	return (tty);
}

t_all		*init_all(char **env)
{
	t_all		*all;

	all = NULL;
	if (!(all = (t_all *)malloc(sizeof(t_all))))
		error("MALLOC");
	all->dupenv = ft_dupenv(env);
	all->data = NULL;
	if (!(all->data = (t_data *)malloc(sizeof(t_data))))
		error("MALLOC");
	all->data->max_rows = 0;
	init_term(all->dupenv);
	init_windows_size(all->data);
	all->select = create_clst();
	return (all);
}
