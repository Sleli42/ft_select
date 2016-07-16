/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 00:10:34 by lubaujar          #+#    #+#             */
/*   Updated: 2016/07/12 00:10:35 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static char	*get_env_var(char **dupenv, char *var)
{
	int		i;

	i = 0;
	if (dupenv && *dupenv)
	{
		while (dupenv[i])
		{
			if (!ft_strncmp(dupenv[i], var, ft_strlen(var)))
				return (dupenv[i] + ft_strlen(var));
			i++;
		}
	}
	return (NULL);
}

void		init_term(t_all *all, char **dupenv)
{
	char			*term_name;

	term_name = NULL;
	if ((term_name = get_env_var(dupenv, "TERM=")) == NULL)
		term_error("GETENV");
	if (tgetent(NULL, term_name) == -1)
		term_error("TGETENT");
	if (tcgetattr(0, &all->term) == -1)
		;
	all->term.c_lflag &= ~(ECHO | ICANON);
	all->term.c_cc[VMIN] = 1;
	all->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &all->term) == -1)
		;
}

void		reset_term(t_all *all)
{
	if (tcgetattr(0, &all->term) == -1)
		;
	all->term.c_lflag = (ECHO | ICANON);
	if (tcsetattr(0, TCSADRAIN, &all->term) == -1)
		;
}

int			lu_putchar(int c)
{
	ft_putchar(c);
	return (0);
}

void		tputs_termcap(char *tc)
{
	char	*res;

	if ((res = tgetstr(tc, NULL)) == NULL)
		return ;
	tputs(res, 0, lu_putchar);
}
