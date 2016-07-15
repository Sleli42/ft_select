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

t_all			*f_cpy(t_all *all)
{
	static t_all *cpy;

	if (all)
		cpy = all;
	return (cpy);
}

void			sig_handler(int sig)
{
	t_all	*all;

	all = NULL;
	if (sig == SIGWINCH)
	{
		if ((all = f_cpy(NULL)) == NULL)
			return (ft_putendl("no signal"));
		reset_term();
		init_term(all->dupenv);
		init_windows_size(all->data);
		define_nb_args_by_row(all->select, all->data);
		define_nb_lines_writed(all->select, all->data);
		tputs_termcap("cl");
		if (all->data->maxlen_arg > all->data->max_cols)
			return (ft_putstr("Too small screen\n"));
		horizontal_display(all->select, all->data);
	}
}

void			sig_catch(void)
{
	int sig;

	sig = 0;
	while (sig++ < 32)
		signal(sig, sig_handler);
}

int				main(int ac, char **av, char **env)
{
	t_all	*all;
	int		ct;

	sig_catch();
	all = init_all(env);
	ct = 0;
	if (ac > 1)
	{
		ft_putchar('\n');
		while (++ct < ac)
			clst_add_elem_back(all->select, clst_create_elem(av[ct]));
		set_index(all->select);
		select_loop(all);
	}
	else
		ft_putendl("Need more args !");
	tputs_termcap("ve");
	return (0);
}
