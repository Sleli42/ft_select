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

char			**create_simple_env(void)
{
	char			**dft_env;
	char			buf[512];

	if ((dft_env = (char **)malloc(sizeof(char *) * 12)) == NULL)
		return (NULL);
	dft_env[0] = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin";
	dft_env[1] = ft_strjoin("PWD=", getcwd(buf, 512));
	dft_env[2] = "SHLVL=1";
	dft_env[3] = "_=/usr/bin/env";
	dft_env[4] = "HOME=/nfs/2014/l/lubaujar";
	dft_env[5] = "TERM=xterm-256color";
	dft_env[6] = "TERM_PROGRAM=iTerm.app";
	dft_env[7] = "PAGER=less";
	dft_env[8] = "LESS=-R";
	dft_env[9] = "LC_CTYPE=";
	dft_env[10] = "LSCOLORS=Gxfxcxdxbxegedabagacad";
	dft_env[11] = NULL;
	return (dft_env);
}

t_all			*f_cpy(t_all *all)
{
	static t_all *cpy;

	if (all)
		cpy = all;
	return (cpy);
}

void			sig_catch(void)
{
	signal(SIGWINCH, sig_winch);
	signal(SIGINT, sig_int);
	signal(SIGCONT, sig_cont);
	signal(SIGTSTP, sig_tstp);
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
